/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:45:42 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/29 15:58:05 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static	uintmax_t	ft_len(uintmax_t n)
{
	uintmax_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa_mod(uintmax_t n)
{
	char		 *arr;
	uintmax_t	len;
	uintmax_t	nb;

	nb = n;
	len = ft_len(n);
	if (!(arr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	arr[len--] = '\0';
	if (n == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	while (nb > 0)
	{
		arr[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (arr);
}
