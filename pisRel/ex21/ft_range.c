/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:43:23 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/05 15:52:38 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*arr;
	int i;
	int	length;

	i = 0;
	if (min >= max)
		return (NULL);
	length = max - min;
	if (!(arr = (int*)malloc(sizeof(*arr) * length)))
		return (NULL);
	while (i < length)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
