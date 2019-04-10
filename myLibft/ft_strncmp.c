/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:32:57 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/10 16:02:12 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*one;
	char	*two;

	one = (char *)s1;
	two = (char *)s2;
	i = 0;
	while (one[i] && i < n)
	{
		if (two[i] == '\0')
			return (1);
		if (one[i] < two[i])
			return (-1);
		if(one[i] > two[i])
			return (1);
		i++;
	}
	if (two[i] != '\0')
		return (-1);
	return (0);
}
