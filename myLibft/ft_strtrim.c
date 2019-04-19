/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:36:42 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/19 15:52:30 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	start = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(s));
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len] == '\0')
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
