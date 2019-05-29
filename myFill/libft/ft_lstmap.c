/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:19:58 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/30 11:38:56 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*curr;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	curr = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp = f(lst);
		if (!(curr->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_lfree(new);
			return (NULL);
		}
		curr = curr->next;
	}
	return (new);
}
