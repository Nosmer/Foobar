/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:43:23 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/04 13:53:36 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*arr;
	int i;
	int	length;

	i = 0;
	length = max - min;
	arr = (int*)malloc(sizeof(*arr) * length);
	if (min >= max)
		return (NULL);
	while (i < length)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
