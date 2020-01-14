/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:06:10 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/14 16:30:47 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Reads user input (STDIN_FILENO) and returns a resulting string.
*/

char		*shell_read(void)
{
	char	*buf;
	char	ch;
	int		bufsize;
	int		pos;

	bufsize = MS_BUFSIZE;
	pos = 0;
	if (!(buf = malloc(sizeof(char) * bufsize)))
	{
		ft_putendl_fd("minishell: allocation error", 2);
		exit(EXIT_FAILURE);
	}
	while ((read(STDIN_FILENO, &ch, 1)) > 0)
	{
		if (ft_strchr(&ch, EOF) || ft_strchr(&ch, '\n'))
		{
			buf[pos] = '\0';
			return (buf);
		}
		else
			buf[pos++] = ch;
		if (pos >= bufsize)
			ft_reallocate(&buf, bufsize);
	}
	return (buf);
}

/*
** Main for testing
**
**int		main(void)
**{	char	*c;
**	int		status;
**
**	status = 1;
**	while (status != 0)
**	{
**		write(1, "$>", 2);
**		c = shell_read();
**		printf("%s\n", c);
**		status = 0;
**		free(c);
**	}
**	return (0);
**}
*/
