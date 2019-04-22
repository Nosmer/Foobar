/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:25:47 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/22 10:40:23 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*arr;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if (!(arr = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		ft_strcpy(arr, s1);
		ft_strcat(arr, s2);
		return (arr);
	}
	return (NULL);
}
