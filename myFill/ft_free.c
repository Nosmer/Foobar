/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:43:52 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/26 15:50:50 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Frees our linked list starting with
** the head while also freeing a map
** of each link.
*/

static void	ft_lst_free(t_tet *head)
{
	t_tet	*tmp;
	int		i;

	while (head != NULL)
	{
		i = 0;
		tmp = head;
		head = head->next;
		while (i < tmp->height)
		{
			free(tmp->map[i]);
			i++;
		}
		free(tmp->map);
		free(tmp);
	}
}

/*
** Clears the map field of our board and
** calls ft_lst_free with the head of our
** linked list as a parameter.
*/

void		ft_free(t_board *board)
{
	int		i;

	i = 0;
	ft_lst_free(board->tets);
	if (board->map)
	{
		while (i < 4 * board->nb_tet)
		{
			free(board->map[i]);
			i++;
		}
		free(board->map);
		board->map = NULL;
	}
}
