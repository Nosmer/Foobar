/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:06:10 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/13 17:07:15 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Reads user input (STDIN_FILENO) and returns a resulting string.
*/

char	*shell_read(void)
{
	char	*buf;
	int		bufsize;
	int		old;
	int		pos;
	int		ch;

	bufsize = MS_BUFSIZE;
	pos = 0;
	old = 0;
	if (!(buf = malloc(sizeof(char) * bufsize)))
	{
		ft_putendl_fd("minishell: allocation error", 2);
		exit(EXIT_FAILURE);
	}
	while ((read(STDIN_FILENO, &ch, 1)) > 0)
	{
		if (ch == EOF || ch == '\n')
		{
			buf[pos] = '\0';
			return (buf);
		}
		else
			buf[pos] = ch;
		pos++;
/*
** Reallocating buf in case we run out of space.
*/
		if (pos >= bufsize)
		{
			old = bufsize;
			bufsize += MS_BUFSIZE;
			if (!(buf = ft_realloc(buf, old, bufsize)))
			{
				ft_putendl_fd("minishell: allocation error", 2);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (buf);
}

/* Main for testing
**
**int		main(void)
**{	char	*c;
**	int		status;
**
**	status = 1;
**	while (status != 0)
**	{
**		c = shell_read();
**		printf("%s\n", c);
**		status = 0;
**		free(c);
**	}
**	return (0);
**}
*/
