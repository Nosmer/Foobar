/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:45:25 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/09 16:21:56 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	if (!(dup = (char*)malloc(sizeof(*dup) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
