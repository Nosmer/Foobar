/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:33:25 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/10 13:27:57 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*us;
	unsigned char	uc;

	uc = (unsigned char)c;
	us = (char *)s;
	i = 0;
	while(us[i])
	{
		if (us[i] == uc)
			return(&us[i]);
		i++;
	}
	return (NULL);
}
