/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:49:31 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/16 12:02:13 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_length(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*arr;
	size_t	len;
	size_t	nb;

	nb = n;
	len = ft_length(n);
	if (!(arr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	arr[len--] = '\0';
	if (n == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	if (n < 0)
	{
		arr[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		arr[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (arr);
}
