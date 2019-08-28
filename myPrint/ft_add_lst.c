/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:29:54 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/28 11:39:36 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

int				ft_add_lst(t_lista **head, char *content)
{
	int			res;
	t_lista		*new;
	t_lista		*last;

	res = 0;
	new = (t_lista *)malloc(sizeof(t_lista));
	new->content = content;
	new->next = NULL;
	last = *head;
	if (*head == NULL)
	{
		*head = new;
		res += ft_strlen(new->content);
		return (res);
	}
	while (last->next)
		last = last->next;
	last->next = new;
	res += ft_strlen(new->content);
	return (res);
}
