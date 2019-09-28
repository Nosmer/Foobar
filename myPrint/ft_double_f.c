/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:24:54 by bconsuel          #+#    #+#             */
/*   Updated: 2019/09/28 14:41:21 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

int		ft_double_f(t_listf *lst, double f)
{
	int		res;
	int		len;
	char	*nb;

	res = 0;
	len = 0;
	if (lst->prec <= 0)
		lst->prec = 7;
	len += ft_ftoa(lst, f, &nb);
	lst->wid = lst->wid - len;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 0)
		res += ft_print(PRNT);
	if (PLUS == '+')
	{
		if (f >= 0)
			res += ft_print('+');
		else
			res += ft_print('-');
	}
	else if (SPACE == ' ')
	{
		if (f != '-')
			res += ft_print(' ');
	}
	ft_putstr(nb);
	free(nb);
	while (MINUS == '-' && (lst->wid)-- > 0)
		res += ft_print(' ');
	return (res + len);
}
