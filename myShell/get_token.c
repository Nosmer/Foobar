/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:30:46 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/08 15:38:16 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Returns an index of the first character of s1
** that is not in s2.
*/

size_t	get_npos(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] && ft_strchr(s2, s1[i]))
		i++;
	return (i);
}

/*
** Returns an index of the first character of s1
** that is in s2.
*/

size_t	get_pos(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

/*
** Splits a string s into tokens pointed at by delim.
** Returns a pointer to the next token in a string if NULL
** is passed after passing said string in the first iteration
** of the function call.
*/

char	*get_token(char *s, const char *delim)
{
	static char	*save;
	char		*end;

	if (s == NULL)
		s = save;
	if (*s == '\0')
	{
		save = s;
		return (NULL);
	}
	s += get_npos(s, delim);
	if (*s == '\0')
	{
		save = s;
		return (NULL);
	}
	end = s + get_pos(s, delim);
	if (*end == '\0')
	{
		save = end;
		return (s);
	}
	*end = '\0';
	save = end + 1;
	return (s);
}
