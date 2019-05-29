/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:27:46 by bconsuel          #+#    #+#             */
/*   Updated: 2019/05/27 15:17:02 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_tet	*init_tet(char *buf)
{
	
}

void	ft_store(t_board *board, char *buf)
{
	t_tet	*new;

	new = init_tet(buf);
	push_tet(board, new);
}
