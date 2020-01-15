/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:38:33 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/15 16:17:54 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies bytes from src to dst. If the character c is found in src,
** process stops and a pointer to the byte after the copy of c in
** the string dst is returned. Otherwise n bytes are copied and NULL
** pointer is returned in the end.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;
	unsigned char	uc;

	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == uc)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
