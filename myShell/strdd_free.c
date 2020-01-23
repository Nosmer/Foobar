/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdd_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:29:34 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/20 13:03:57 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	strdd_free(char **source)
{
	size_t	i;

	i = 0;
	while (source[i])
	{
		free(source[i]);
		i++;
	}
	free(source);
}