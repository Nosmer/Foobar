/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:14:22 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/03 13:56:27 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

int		ft_char(t_listf *lst, int c)
{
	int		res;

	res = 0;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 1)
		res += ft_print(PRNT);
	res += ft_print(c);
	while (MINUS == '-' && (lst->wid)-- > 1)
		res += ft_print(' ');
	return (res);
}
