/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:55:31 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/16 12:54:20 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates memory for a fresh string filled with null-terminators.
** Returns a pointer to said memory.
*/

char	*ft_strnew(size_t size)
{
	char	*arr;

	if (!(arr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(arr, '\0', size + 1);
	return (arr);
}
