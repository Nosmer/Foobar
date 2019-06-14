/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:21:15 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/12 12:49:48 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Clears the map field of our board, since it is the only place
 * where memory is allocated.
 */
static void	ft_free(t_board *board)
{
	int i;
	
	i = 0;
	if (board->map)
	{
		while (i < 4 * board->nb_tet)
		{
			free(board->map);
			i++;
			board->map = NULL;
		}
	}
}

/*
 * Displays entire map of the board. Since our board
 * is equilateral, we can use board->size for both dimensions.
 */
static void	ft_display(t_board *board)
{
	int		i;
	int		j;

	i = 0;
	while (i < board->size)
	{
		j = 0;
		while (j < board->size)
		{
			ft_putchar(board->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/*
 * First initializes the board and validates argv[1] with ft_init
 * by checking the right number of # and shape of our tetrimino.
 * If argv[1] is validated, ft_init assigns a letter to each
 * tetrimino and puts them on board in order of their appearance
 * in the file.
 */
int			main(int argc, char **argv)
{
	t_board	board;

	if (argc > 2)
	{
		ft_puterr(1);
	}
	else
	{
		if (ft_init(&board, argv[1]))
		{
			ft_solve(&board);
			ft_display(&board);
			ft_free(&board);
		}
		else
			ft_puterr(0);
	}
	return (0);
}
