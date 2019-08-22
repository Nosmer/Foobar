/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:32:16 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/22 15:26:24 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static int	ft_putnbr_uint(uintmax_t u)
{
	int		res;

	res = 0;
	if (u >= 10)
		res += ft_putnbr_uint(u / 10);
	res += ft_print(u % 10 + '0');
	return (res);
}

static int	ft_get_uilen(uintmax_t u)
{
	int			res;
	uintmax_t	temp;

	res = 0;
	temp = u;
	if (temp >= 10)
		res += ft_get_uilen(temp / 10);
	res++;
	return (res);
}

static int	ft_put_uint(t_listf *lst, uintmax_t u)
{
	int		res;

	res = 0;
	lst->wid = lst->wid - ft_get_uilen(u);
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 0)
		res += ft_print(PRNT);
	res += ft_putnbr_uint(u);
	while (MINUS == '-' && (lst->wid)-- > 0)
		res += ft_print(' ');
	return (res);
}

int			ft_uint(t_listf *lst, void *u)
{
	int		res;

	res = 0;
	if (lst->l)
		res += ft_put_uint(lst, (unsigned long)u);
	else if (lst->ll)
		res += ft_put_uint(lst, (unsigned long long)u);
	else if (lst->h)
		res += ft_put_uint(lst, (unsigned short)u);
	else if (lst->hh)
		res += ft_put_uint(lst, (unsigned char)u);
	else
		res += ft_put_uint(lst, (unsigned int)u);
	return (res);
}
