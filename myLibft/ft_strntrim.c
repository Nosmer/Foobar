/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strntrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:27:24 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/24 13:33:18 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strntrim(char const *s, int c)
{
	size_t	start;
	size_t	len;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(s));
	start = 0;
	len = ft_strlen(s);
	while (s[start] == (unsigned char)c)
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	while (s[len] == (unsigned char)c)
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
