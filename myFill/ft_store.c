/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:27:46 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/24 15:45:17 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Places new tetrimino at the end of the board
** and counts the number of tetriminos in it.
** Easy.
*/

void			push_new(t_board *board, t_tet *new)
{
	t_tet	*tet;

	tet = board->tets;
	if (!tet)
	{
		board->tets = new;
		board->nb_tet++;
		return ;
	}
	while (tet->next)
		tet = tet->next;
	tet->next = new;
	board->nb_tet++;
}

/*
** Creates a new string to place in map[i] of our tet
** and replaces all # with chatacter passed to char l.
*/

static char		*re_piece(char const *s, unsigned int start,
								int len, char l)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = ft_strnew(len)))
		ft_puterr(0);
	while (i < len)
	{
		if (s[start + i] == '#')
			result[i] = l;
		else
			result[i] = '.';
		i++;
	}
	return (result);
}

/*
** Calculates a coordinate of the first tetri #
** regarding top, bottom, left and right borders.
** Using struct coord instead of *coord to avoid
** exessive memory allocation.
*/

static t_coord	get_coords(char *buf)
{
	t_coord coord;
	int		i;

	i = 0;
	coord.top = 3;
	coord.bottom = 0;
	coord.left = 3;
	coord.right = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (i / 5 < coord.top)
				coord.top = i / 5;
			if (i / 5 > coord.bottom)
				coord.bottom = i / 5;
			if (i % 5 > coord.right)
				coord.right = i % 5;
			if (i % 5 < coord.left)
				coord.left = i % 5;
		}
		i++;
	}
	return (coord);
}

/*
** Initializes a new tet structure to store
** our valid buf and pushes it to the end of our board
** with push_new(). Pts stores a coordinate of the first #
** in tetrimino.
*/

void			ft_store(t_board *board, char *buf)
{
	t_tet		*new;
	t_coord		pts;
	int			i;
	static char	c = 'A';

	i = 0;
	if (!(new = ft_memalloc(sizeof(t_tet))))
		ft_puterr(0);
	pts = get_coords(buf);
	new->letter = c++;
	new->next = NULL;
	new->width = pts.right - pts.left + 1;
	new->height = pts.bottom - pts.top + 1;
	if (!(new->map = (char **)malloc(new->height * sizeof(char *))))
		ft_puterr(0);
	while (i < new->height)
	{
		new->map[i] = re_piece(buf, ((pts.top + i) * 5 + pts.left),
				new->width, new->letter);
		i++;
	}
	push_new(board, new);
}
