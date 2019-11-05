/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:55:31 by bconsuel          #+#    #+#             */
/*   Updated: 2019/05/14 14:10:58 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*arr;

	if (!(arr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(arr, '\0', size + 1);
	return (arr);
}
