/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:27:53 by bconsuel          #+#    #+#             */
/*   Updated: 2019/05/27 14:44:03 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_init(t_board *board, char *file)
{
	board->tet = NULL;
	board->nb_tet = 0;
	board->map = NULL;
	if (ft_validate(board, file))
	{
		set_board(board, 4 * board->nb_tet);
		board->size = 2 * ft_sqrt(board->nb_tet) - 1;
		return (1);
	}
	return (0);
}
