/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:59:33 by bconsuel          #+#    #+#             */
/*   Updated: 2019/05/14 14:48:52 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		next_line(char **c, char **line, int fd)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while (c[fd][len] != '\n' && c[fd][len] != '\0')
		len++;
	if (c[fd][len] == '\n')
	{
		*line = ft_strsub(c[fd], 0, len);
		tmp = ft_strdup(c[fd] + (len + 1));
		free(c[fd]);
		c[fd] = tmp;
	}
	else if (c[fd][len] == '\0')
	{
		*line = ft_strdup(c[fd]);
		ft_strdel(&c[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*c[1024];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (fd > 1024 || fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (c[fd] == NULL)
		c[fd] = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(c[fd], buf);
		free(c[fd]);
		c[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (c[fd] == NULL || c[fd][0] == '\0'))
		return (0);
	return (next_line(c, line, fd));
}
