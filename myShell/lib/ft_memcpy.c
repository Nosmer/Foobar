/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:55:23 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/15 16:15:31 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *c1;
	unsigned char *c2;

	c1 = (unsigned char *)dst;
	c2 = (unsigned char *)src;
	while (n--)
	{
		*c1 = *c2;
		c1++;
		c2++;
	}
	return (dst);
}
