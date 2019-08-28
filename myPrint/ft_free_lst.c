/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:43:27 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/28 12:03:58 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

void			ft_free_lst(t_lista *head)
{
	t_lista		*tmp;

	while(head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
