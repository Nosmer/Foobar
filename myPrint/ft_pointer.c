/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:28:23 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/23 12:47:08 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static int	ft_get_pntr(char *hex, size_t p)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	while (p != 0)
	{
		t = p % 16;
		if (t < 10)
			hex[i++] = t + 48;
		else
			hex[i++] = t + 87;
		p = p / 16;
	}
	hex[i++] = 'x';
	hex[i] = '0';
	return (i + 1);
}

int			ft_pointer(t_listf *lst, void *p)
{
	char	hex[100];
	int		res;
	int		len;

	res = 0;
	len += ft_get_pntr(hex, (size_t)p);
	lst->wid = lst->wid - len + 1;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 1)
		res += ft_print(PRNT);
	ft_prnt_arr(hex, len);
	while (MINUS == '-' && (lst->wid)-- > 1)
		res += ft_print(' ');
	return (res + len);
}
