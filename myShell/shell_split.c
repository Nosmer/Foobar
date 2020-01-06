/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:08:46 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/06 16:27:02 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (pos >= bufsize)
		{
			old = bufsize;
			bufsize += MS_TOK_BUFSIZE;
			if (!(tokens = ft_realloc(buf, old, bufsize)))
			{
				ft_putendl_fd("minishell: allocation error", 2);
				exit(EXIT_FAILURE);
			}
		}
		token = get_token(NULL, MS_TOK_DELIM);
	}
	token[pos] = NULL;
	return (tokens);
}
