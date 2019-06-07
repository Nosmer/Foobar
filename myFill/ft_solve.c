/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:22:20 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/05 16:15:58 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * First we try to put a tetrimino on x/y position, if
 * we fail - delete the last tetr and try again with 
 * the next x/y position. Returns 1 if we found an answer
 * (for recursion) or ran out of tetriminoes. 
 */
static int	solving(t_board *board, t_tet *tet)
{
	if (!tet)
		return (1);
	tet->x = 0;
	while (tet->x + tet->width <= board->size)
	{
		tet->y = 0;
		while (tet->y + tet->height <= board->size)
		{
			if (map_add(board, tet))
			{
				if (solving(board, tet->next))
					return (1);
				else
					map_del(board, tet, tet->width, tet->height)
			}
			tet->y++;
		}
		tet->x++;
	}
	return (0);
}

/*
 * Provides us with a main loop for solving the task.
 * Tries to solve the task, if fails to do so, increases
 * the size of the board and resets the map by filing it
 * with '.'
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
