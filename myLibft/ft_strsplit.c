/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:28:31 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/29 14:00:00 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len_delim(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i] != c && s[i] != '\0')
				len++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (len);
}

static	size_t	ft_word_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static	void	ft_free(char **arr, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_len_delim(s, c);
	if (!s || !(arr = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		while (s[j] == c)
			j++;
		if (!(arr[i] = ft_strsub(s, j, ft_word_len(&s[j], c))))
		{
			ft_free(arr, i);
			return (NULL);
		}
		while (s[j] != c)
			j++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
