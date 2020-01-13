/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:08:46 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/13 17:03:36 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Splits the given line into tokens
** and puts them in 2d array.
*/

char	**shell_split(char *line)
{
	int		bufsize;
	int		old;
	int		pos;
	char	**tokens;
	char	*token;

	bufsize = MS_TOK_BUFSIZE;
	old = 0;
	pos = 0;
	if (!(tokens = malloc(bufsize * sizeof(char*))))
	{
		ft_putendl_fd("minishell: allocation error", 2);
		exit(EXIT_FAILURE);
	}
	token = get_token(line, MS_TOK_DELIM);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
/*
** Reallocating tokens in case we run out of space.
*/
		if (pos >= bufsize)
		{
			old = bufsize;
			bufsize += MS_TOK_BUFSIZE;
			if (!(tokens = ft_realloc(tokens, old, bufsize)))
			{
				ft_putendl_fd("minishell: allocation error", 2);
				exit(EXIT_FAILURE);
			}
		}
		token = get_token(NULL, MS_TOK_DELIM);
	}
	tokens[pos] = NULL;	
	return (tokens);
}

/* Main for testing
**
**int		main(void)
**{
**	char	line[50] = "FooBar1 FooBar2 FooBar3\n";
**	char	**args;
**	int		status;
**	int		i;
**
**	args = shell_split(line);
**	i = 0;
**	while (args[i])
**	{
**		printf("%s\n", args[i]);
**		i++;
**	}
**}
*/
