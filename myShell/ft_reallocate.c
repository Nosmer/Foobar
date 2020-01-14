/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:36:42 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/14 15:46:56 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Reallocates memory in case we are running out of bounds.
** 25 lines limit is a terrible thing.
*/

void	ft_reallocate(char **tokens, int bufsize)
{
	int		old;

	old = bufsize;
	bufsize += MS_TOK_BUFSIZE;
	if (!(tokens = ft_realloc(tokens, old, bufsize)))
	{
		ft_putendl_fd("minishell: allocation error", 2);
		exit(EXIT_FAILURE);
	}
}
