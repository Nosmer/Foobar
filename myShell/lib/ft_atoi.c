/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:19:14 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/15 16:57:56 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts the initial portion of the string pointed to by str to
** integer representation.
*/

int	ft_atoi(const char *str)
{
	long		result;
	int			sign;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
	{
		sign = -1;
	}
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((result = result * 10 + *str - '0') < 0)
			return (sign == 1 ? -1 : 0);
		str++;
	}
	return (result * sign);
}
