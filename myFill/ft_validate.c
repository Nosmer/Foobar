/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 13:27:01 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/26 15:06:17 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Returns the number of connections around # character
** in buf. First checks previous character, then next one,
** then the one above, then the one below.
*/

static	int	valid_shape(char *buf)
{
	int	val;
	int	i;

	val = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (i > 0 && buf[i - 1] == '#')
				val++;
			if (i < 19 && buf[i + 1] == '#')
				val++;
			if (i >= 5 && buf[i - 5] == '#')
				val++;
			if (i <= 14 && buf[i + 5] == '#')
				val++;
		}
		i++;
	}
	return (val);
}

/*
** Conveniently checks if our passed string has the correct
** characters and returns 1 if they are placed correctly,
** 0 otherwise.
*/

static	int	valid_char(char c, int i)
{
	if (c == '#' || c == '.' || (c == '\n'
			&& (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)))
		return (1);
	return (0);
}

/*
** Checks the validity of our tetrimino. valid_char is for convenient
** check of characters. Val stores the number of connections between
** # characters, that we count in valid_shape func. Returns 1 if
** buf is valid, calls ft_puterr(0) otherwise.
*/

static	int	valid_buf(char *buf)
{
	int	i;
	int	tet;
	int	val;

	i = 0;
	tet = 0;
	while (buf[i])
	{
		if (!valid_char(buf[i], i))
			ft_puterr(0);
		if (buf[i] == '#')
			tet++;
		i++;
	}
	val = valid_shape(buf);
	if (tet == 4 && (val == 6 || val == 8))
		return (1);
	else
		ft_puterr(0);
	return (0);
}

/*
** Reads our file in increments of 22 and passes them into
** valid_buf() func. If passed buf(fer) is correct, we call
** ft_store() func to put our valid block on the board, otherwise
** calls ft_puterr(0).
*/

int			ft_validate(t_board *board, const char *file)
{
	int		fd;
	int		ret;
	int		last;
	int		count;
	char	buf[22];

	last = 0;
	count = 0;
	if (!(fd = open(file, O_RDONLY)))
		ft_puterr(0);
	while ((ret = read(fd, buf, 21)))
	{
		last = ret;
		buf[ret] = '\0';
		if (ret >= 20 && valid_buf(buf))
		{
			ft_store(board, buf);
			count++;
		}
		else
			ft_puterr(0);
	}
	if ((ret <= 0 && (last == 21 || !last)) || count > 26)
		ft_puterr(0);
	return (1);
}
