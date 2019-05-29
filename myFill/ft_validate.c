/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 13:27:01 by bconsuel          #+#    #+#             */
/*   Updated: 2019/05/27 15:12:36 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	valid_shape(char *buf, int t)
{
	int	val;

	val = 0;
	if (t == 19)
		return (val);
	while (buf[t])
	{
		if (buf[t] == '#')
		{
			if (t > 0 && buf[t - 1] == '#')
				val++;
			if (t < 19 && buf[t + 1] == '#')
				val++;
			if (t >= 5 && buf[t - 5] == '#')
				val++;
			if (t <= 14 && buf[t + 5] == '#')
				val++;
		}
		t++;
	}
	return (val);
}

static	int	valid_char(char c, int i)
{
	if (c == '#' || c == '.' || (c == '\n'
			   	&& (i == 4 || i == 9 || i == 14 || i == 19)))
		return (1);
	return (0);
}

static	int	valid_buf(char *buf)
{
	int	i;
	int	tet;
	int	first_t;
	int	val;

	i = 0;
	tet = 0;
	first_t = 0;
	while (buf[i] && valid_char(buf[i], i))
	{
		if (buf[i] == '#')
		{
			tet++;
			if (tet == 1)
				first_t = i;
		}
		i++;
	}
	val = valid_shape(buf, first_t);
	if (tet == 4 && (val == 6 || val == 8))
		return (1);
	else
		ft_puterr(0);
	return (0);
}

int			ft_validate(t_board board, const char *file)
{
	int		fd;
	int		ret;
	char	buf[22];

	if (!(fd = open(file, O_RDONLY)))
		ft_puterr(0);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (ret >= 20 && valid_buf(buf))
			ft_store(board, buf);
		else
			ft_puterr(0);
	}
	return (1);
}
