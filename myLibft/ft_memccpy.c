/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:38:33 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/09 13:41:30 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memccpy(void *dst, const *src, int c, size_t n)
{
	size_t	i;
	unsigned const char	*src1;
	unsigned char		*dst1;
	unsigned char 		uc;

	src1 = (char *)src;
	dst1 = (char *)dst;
	uc = (unsigned char)c;
	i = 0;
	while(i < n)
	{
		dst1[i] = src1[i];
		if(src1[i] == uc)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
