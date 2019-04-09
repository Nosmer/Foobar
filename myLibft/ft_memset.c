/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:29:49 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/08 15:18:03 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uc;

	uc = (unsigned char *)b;
	while (len--)
	{
		*uc = (unsigned char)c;
		uc++;
	}
	return (b);
}
