/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:36:21 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/03 13:56:06 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

int			ft_percent(t_listf *lst)
{
	int		res;

	res = 0;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 1)
	{
		res += ft_print(PRNT);
	}
	res += ft_print('%');
	while (MINUS == '-' && (lst->wid)-- > 1)
	{
		res += ft_print(' ');
	}
	return (res);
}
