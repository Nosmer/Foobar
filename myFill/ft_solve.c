/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:22:20 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/18 13:43:03 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Deletes a selected tet from the board.
*/

static int	map_del(t_board *board, t_tet *tet)
{
	int		i;
	int		j;

	i = 0;
	while (i <= board->size)
	{
		j = 0;
		while (j <= board->size)
		{
			if (B_MAP_POS == tet->letter)
				B_MAP_POS = '.';
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Tries to add a tet on the board. If both chosen
** positions arent '.' (which means its either end of the line
** or it found an occupied space on the board) then
** function stops and returns 0. Calls map_del() to clear the board
** from the current tetrimino if not '.' fount in the middle of
** the string.
*/

static int	map_add(t_board *board, t_tet *tet)
{
	int		i;
	int		j;

	i = 0;
	if (board->map[tet->x][tet->y] != '.' && tet->map[0][0] != '.')
		return (0);
	while (i < tet->height)
	{
		j = 0;
		while (j < tet->width)
		{
			if (B_MAP_POS != '.' && T_MAP_POS != '.')
				return (map_del(board, tet));
			else if (B_MAP_POS == '.')
				B_MAP_POS = T_MAP_POS;
			j++;
		}
		i++;
	}
	return (1);
}

/*
** First this func tries to put a tetrimino on x/y position,
** if it fails - deletes tet from the map and tries again
** with the next x/y position. Returns 1 if the answer
** is found (for recursion) or it ran out of tetriminoes
** (which means we found our solution).
*/

static int	solving(t_board *board, t_tet *tet)
{
	if (!tet)
		return (1);
	tet->x = 0;
	while (tet->x + tet->height <= board->size)
	{
		tet->y = 0;
		while (tet->y + tet->width <= board->size)
		{
			if (map_add(board, tet))
			{
				if (solving(board, tet->next))
					return (1);
				else
					map_del(board, tet);
			}
			tet->y++;
		}
		tet->x++;
	}
	return (0);
}

/*
** Provides a main loop for solving the task.
** Tries to solve the task, if fails to do so, increases
** the size of the board and resets the map by calling
** ft_memset to fil the board with '.'
*/

void		ft_solve(t_board *board)
{
	int		i;

	while (!solving(board, board->tets))
	{
		board->size++;
		i = 0;
		while (i < board->size)
		{
			ft_memset(board->map[i], '.', board->size);
			i++;
		}
	}
}
