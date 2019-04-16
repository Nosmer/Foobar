/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:56 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/11 11:37:17 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	char	*one;
	char	*two;

	one = (char *)s1;
	two = (char *)s2;
	i = 0;
	while (one[i])
	{
		if (two[i] == '\0')
			return (1);
		if (one[i] < two[i])
			return (-1);
		if (one[i] > two[i])
			return (1);
		i++;
	}
	if (two[i] != '\0')
		return (-1);
	return (0);
}
