/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:32:27 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/29 15:21:03 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*rrange(int	start, int end)
{
	int		*rrange;
	int		len;

	if (start >= end)
		len = start - end + 1;
	else
		len = end - start + 1;
	if (!(rrange = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (len--)
		rrange[len] = (end >= start) ? start++ : start--;
	return (rrange);
}

int		main()
{
	return (0);
}
