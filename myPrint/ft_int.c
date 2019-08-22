/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:27:42 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/22 14:48:36 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static int ft_putnbr_mod(intmax_t di)
{
	int		res;

	res = 0;
	if (di < 0)
	{
		di *= -1;
		res += ft_print('-');
	}
	if (di >= 10)
		res += ft_putnbr_mod(di / 10);
	res += ft_print(di % 10 + '0');
	return (res);
}

static int	ft_get_dilen(intmax_t di)
{
	int		res;
	int		temp;

	res = 0;
	temp = di;
	if (temp >= 10)
		res += ft_get_dilen(temp / 10);
	res++;
	return (res);
}

static int	ft_put_di(t_listf *lst, intmax_t di)
{
	int		res;

	res = 0;
	lst->wid = lst->wid - ft_get_dilen(di);
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 0)
		res += ft_print(PRNT);
	if (PLUS == '+')
	{
		if (di >= 0)
			res += ft_print('+');
		else
			res += ft_print('-');
		res += ft_putnbr_mod(di);
	}
	else if (SPACE == ' ')
	{
		if (di != '-')
			res += ft_print(' ');
		res += ft_putnbr_mod(di);
	}
	else
		res += ft_putnbr_mod(di);
	while (MINUS == '-' && (lst->wid)-- > 0)
		res += ft_print(' ');
	return (res);
}

int			ft_int(t_listf *lst, void *di)
{
	int		res;

	res = 0;
	if (lst->l)
		res += ft_put_di(lst, (long)di);
	else if (lst->ll)
		res += ft_put_di(lst, (long long)di);
	else if (lst->h)
		res += ft_put_di(lst, (short)di);
	else if (lst ->hh)
		res += ft_put_di(lst, (char)di);
	else
		res += ft_put_di(lst, (int)di);
	return (res);
}
