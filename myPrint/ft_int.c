/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:27:42 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/03 15:30:25 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static int ft_putnbr_mod(t_listf *lst, intmax_t *di)
{
	int			res;

	res = 0;
	if (di < 0)
		di *= -1;
	if (di >= 10)
		ft_putnbr_mod(lst, di / 10);
	res += ft_print(di % 10 + '0');
	return (res);
}

static int	ft_put_di(t_listf *lst, intmax_t *di)
{
	int		res;

	res = 0;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 1)
		res += ft_print(PRNT);
	if (PLUS == '+')
	{
		if (di >= 0)
			res += ft_print('+');
		else
			res += ft_print('-');
		res += ft_putnbr_mod(lst, di);
	}
	else if (SPACE == ' ')
	{
		if (*di != '-')
			res += ft_print(' ');
		res += ft_putnbr_mod(lst, di);
	}
	while (MINUS == '-' && (lst->wid)-- > 1)
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
