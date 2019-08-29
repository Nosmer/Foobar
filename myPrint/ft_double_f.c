/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:19:19 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/29 16:03:24 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"
#include <stdio.h>

static uintmax_t	ft_get_ml(int n)
{
	uintmax_t	res;

	res = 1;
	while (n--)
		res *= 10;
	return (res);
}

static int			ft_get_df(t_listf *lst, t_lista **head, double f)
{
	int			res;
	uintmax_t	ml;
	uintmax_t	left;
	double		right;

	res = 0;
	if (f < 0)
	{
		f *= -1;
		res += ft_add_lst(head, "-");
	}
	left = (uintmax_t)f;
	right = f - (double)left;
	res += ft_add_lst(head, ft_itoa_mod(left));
	if (lst->prec > 0 || HASH == '#')
		res += ft_add_lst(head, ".");
	ml = ft_get_ml(lst->prec);
	right *= ml;
	left = (uintmax_t)(right + 0.5);
	res += ft_add_lst(head, ft_itoa_mod(left));
	return (res);
}

int					ft_double_f(t_listf *lst, double f)
{
	t_lista	*head;
	int		res;
	int		len;

	res = 0;
	len = 0;
	head = NULL;
	if (lst->prec == -1)
		lst->prec = 6;
	len += ft_get_df(lst, &head, f);
	lst->wid = lst->wid - len;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 0)
		res += ft_print(PRNT);
	ft_prnt_lst(head);
	ft_free_lst(head);
	while (MINUS == '-' && (lst->wid)-- > 0)
		res += ft_print(' ');
	return (res + len);
}
