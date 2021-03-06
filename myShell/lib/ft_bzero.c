/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:23:53 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/15 16:14:14 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes n zeroes to the string s.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*uc;

	i = 0;
	uc = (unsigned char *)s;
	if (n > 0)
	{
		while (i < n)
		{
			*uc = 0;
			i++;
			uc++;
		}
	}
}
