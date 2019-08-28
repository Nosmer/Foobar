/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:41:12 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/28 12:05:15 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

void		ft_prnt_lst(t_lista *head)
{
	t_lista		*tmp;

	tmp = head;
	while(tmp)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
}
