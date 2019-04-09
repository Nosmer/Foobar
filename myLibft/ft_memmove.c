/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:15:10 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/09 13:43:14 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	unsigned const char *src1;
	unsigned char 		*dst1;
	char 				tmp[len];

	src1 = (char *)src;
	dst1 = (char *)dst;
	i = 0;
	while (i < len)
	{
		tmp[i] = src1[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst1[i] = tmp[i];
		i++;
	}
	return (dst);
}
