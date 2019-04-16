/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:28:31 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/16 12:04:59 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len_delim(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			len++;
		i++;
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
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static	void	ft_free(char **arr, ssize_t i)
{
	ssize_t	j;

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
	ssize_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = -1;
	len = ft_len_delim(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (++j < len)
	{
		while (s[i] == c)
			i++;
		if (!(arr[j] = ft_strsub(s, i, ft_word_len(&s[j], c))))
		{
			ft_free(arr, j);
			return (NULL);
		}
		while (s[i] != c)
			i++;
	}
	arr[i] = "\0";
	return (arr);
}
