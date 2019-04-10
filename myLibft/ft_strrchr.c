/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:07:50 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/10 13:47:30 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			*us;
	unsigned char	uc;

	uc = (unsigned char)c;
	us = (char *)s;
	i = ft_strlen(us);
	while (us[i])
	{
		if (us[i] == uc)
			return (&us[i]);
		i--;
	}
	return (NULL);
}
