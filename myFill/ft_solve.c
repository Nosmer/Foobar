/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:22:20 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/11 12:57:04 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Deletes a tet from the board.
 */
static int	map_del(t_board *board, t_tet *tet, int hei, int wid)
{
	int		i;
	int		j;

	i = 0;
	while (i <= wid)
	{
		j = 0;
		while (j <= hei)
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
 * Tries to add a tet on the board. We use flag to
 * indicate the state of the func and conveniently store
 * the i/j position for map_del to use in the future.
 * If flag == 1 then everything is fine and func keeps working,
 * if flag == 0 then we stop our function and call map_del.
 */
static int	map_add(t_board *board, t_tet *tet)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 1;
	if (board->map[tet->x][tet->y] != '.' && tet->map[0][0] != '.')
		return (0);
	while (flag && i < tet->height)
	{
		j = 0;
		while(flag && j < tet->width)
		{
			if (B_MAP_POS != '.' && tet->map[i][j] != '.')
				flag = 0;
			else if(B_MAP_POS == '.')
				B_MAP_POS = tet->map[i][j];
			j = (flag)? j + 1 : j;
		}
		i = (flag)? i + 1 : i;
	}
	if (flag)
		return (1);
	return (map_del(board, tet, i, j));
}

/*
 * First this func tries to put a tetrimino on x/y position,
 * if it fails - delete tet from the map and tries again
 * with the next  x/y position. Returns 1 if the answer
 * is found (for recursion) or it ran out of tetriminoes
 * (which means we found our solution).
 */
static int	solving(t_board *board, t_tet *tet)
{
	if (!tet)
		return (1);
	tet->x= 0;
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
					map_del(board, tet, tet->width - 1, tet->height - 1);
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
