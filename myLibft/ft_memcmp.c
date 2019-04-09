/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:35:26 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/09 14:32:30 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char	*first;
	unsigned char	*second;

	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	i = 0;
	if (first == NULL && second == NULL)
		return (0);
	while (i < n)
	{
		if (first[i] != second [i])
			return (first - second);
		i++;
	}
	return (0);
}
