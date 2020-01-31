/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:48:55 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/31 16:01:34 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
size_t			get_et(const char *s1, const char *s2)
{
	size_t		i;
	
	i = 0;
	while (s1[i] && ft_strchr(s2, s1[i]))
		i++;
	return (i);
}

char			*get_insane(char *s, const char *delim)
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
	s += get_et(s, delim);
	if (*s == '\0')
	{
		save = s;
		return (NULL);
	}
	end = s + get_et(s, delim);
	if (*end == '\0')
	{
		save = end;
		return (s);
	}
	*end = '\0';
	save = end + 1;
	return (s);
}

char			**get_words(char *str)
{
	int			i;
	char		*word;
	char		**words;
	int			bufsize;

	i = 0;
	bufsize = MS_TOK_BUFSIZE;
	if (!(words = malloc(bufsize * sizeof(char *))))
	{
		ft_putendl_fd("minishell: allocation error", 2);
		exit(EXIT_FAILURE);
	}
	word = get_insane(str, " $");
	while (word != NULL)
	{
		words[i] = word;
		i++;
		if (i >= bufsize)
			ft_reallocate(words, bufsize);
		word = get_insane(NULL, " $");
	}
	words[i] = NULL;
	return (words);
}

int		main(int argc, char **argv, char **envp)
{
	char	line[50] = "FooBar${HOME}FooBar $PWD FooBar";
	char	**words;

	words = get_words(line);
	while (*words)
	{
		printf("%s\n", *words);
		words++;
	}
	return (0);
}
