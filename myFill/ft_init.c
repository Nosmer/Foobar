/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:27:53 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/11 12:14:19 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Returns square root of x.
 * Easy.
 */
static int		ft_sqrt(int x)
{
	int		res;

	res = 1;
	while (res * res < x)
		res++;
	return (res);
}


/*
 * Allocates memory for the map of our board and
 * fills it with '.'
 */
static void		set_board_map(t_board *board, int s)
{
	int		i;

	i = 0;
	if(!(board->map = (char **)malloc(s * sizeof(char *))))
		ft_puterr(0);
	while (i < s)
	{
		if (!(board->map[i] = (char *)malloc(s * sizeof(char))))
			ft_puterr(0);
		ft_memset(board->map[i], '.', s);
		i++;
	}
}

/*
 * Initializes main board for our tetriminos to place and
 * calls ft_validate to check the correctness of our file.
 * We pass board to ft_validate to immediately put a valid
 * block in it.
 */
int				ft_init(t_board *board, char *file)
{
	board->tets = NULL;
	board->nb_tet = 0;
	board->map = NULL;
	if (ft_validate(board, file))
	{
		set_board_map(board, 4 * board->nb_tet);
		board->size = 2 * ft_sqrt(board->nb_tet) - 1;
		return (1);
	}
	return (0);
}
