/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:06:10 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/06 16:24:15 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while ((read(stdin, &ch, 1)) > 0)
	{
		if (ch == EOF || ch == '\n')
		{
			buf[pos] = '\0';
			return (buf);
		}
		else
			buf[pos] = ch;
		pos++;
		if (pos >= bufsize)
		{
			old = bufsize
			bufsize += MS_BUFSIZE;
			if (!(buf = ft_realloc(buf, old, bufsize)))
			{
				ft_putendl_fd("minishell: allocation error", 2);
				exit(EXIT_FAILURE);
			}
		}
	}
}