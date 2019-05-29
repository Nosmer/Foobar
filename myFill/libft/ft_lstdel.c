/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:40:08 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/29 13:43:07 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;

	curr = *alst;
	while (curr != NULL)
	{
		del(curr->content, curr->content_size);
		free(curr);
		curr = curr->next;
	}
	*alst = NULL;
}
