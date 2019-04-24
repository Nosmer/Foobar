/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:41:35 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/23 15:53:00 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size < (dlen + 1) || size == 0)
	{
		if (size)
			ft_strncat(dst, src, 0);
		return (slen + size);
	}
	else
		ft_strncat(dst, src, size - dlen - 1);
	return (dlen + slen);
}
