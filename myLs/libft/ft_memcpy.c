/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:55:23 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/11 11:32:41 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
