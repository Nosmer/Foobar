/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:19:19 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/24 15:00:00 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"
#include <stdio.h>

static void	ft_lstprnt(t_list *head)
{
	while (head)
	{
		ft_putnbr((int)head->content);
		head = head->next;
	}
}

static int	ft_get_fdbl(t_listf *lst, t_list *head, double f)
{
	int		res;
	int		left;
	double	right;
	t_list	*new;

	res = 0;
	if (f < 0)
	{
		f *= -1;
		res += ft_print('-');
	}
	left = (int)f;
//put left into structure here
	right = f - (double)left;
	while (lst->prec)
	{
		right *= 10;
		left = (int)right;
		right = right - (double)left;
		(lst->prec)--;
//put left into structure here
	}
	return (res);
}

int			ft_double_f(t_listf *lst, double f)
{
	t_list	head;
	int		res;
	int		len;

	res = 0;
	len = 0;
	if (lst->prec == -1)
		lst->prec = 6;
	len += ft_get_fdbl(lst, &head ,f);
	lst->wid = lst->wid - len;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 0)
		res += ft_print(PRNT);
//	ft_prnt_sign(lst, f);
//	ft_lstprnt(&head);
	while (MINUS == '-' && (lst->wid)-- > 0)
		res += ft_print(' ');
	return (res);
}
