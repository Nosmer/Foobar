/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:04:05 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/16 12:51:43 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates a fresh memory area initialized to 0.
** Returns a pointer to said area.
*/

void	*ft_memalloc(size_t size)
{
	void *arr;

	if (!(arr = malloc(size)))
		return (NULL);
	ft_memset(arr, 0, size);
	return (arr);
}
