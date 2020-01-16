/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:04:01 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/16 13:01:04 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies function f to each character of a string s.
** Stores result in arr. Returns arr if operation is successful.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*arr;

	i = 0;
	if (s && f)
	{
		if (!(arr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[i])
		{
			arr[i] = f(s[i]);
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (NULL);
}
