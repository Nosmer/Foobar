/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:08:05 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/09 13:44:02 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*ps;
	unsigned char		uc;

	ps = (char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if(ps[i] == uc)
			return(&ps[i]);
		i++;
	}
	return (NULL);
}
