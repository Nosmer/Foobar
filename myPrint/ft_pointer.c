/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:28:23 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/03 13:57:10 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static	int	get_hex(t_listf *lst, size_t s)
{
	char	hex[100];
	int		i;
	int		j;
	int		t;

	i = 0;
	t = 0;
	while (s != 0)
	{
		t = s % 16;
		if (t < 10)
			hex[i++] = t + 48;
		else
			hex[i++] = t + 87;
		s = s / 16;
	}
	hex[i++] = 'x';
	hex[i] = '0';
	j = i;
	while (j >= 0)
		ft_putchar(hex[j--]);
	return (i);
}

int			ft_pointer(t_listf *lst, void *p)
{
	int		res;

	res = 0;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 1)
		res += ft_print(PRNT);
	res += get_hex(lst, (size_t)p);
	while (MINUS == '-' && (lst->wid)-- > 1)
		res += ft_print(' ');
	return (res);
}
