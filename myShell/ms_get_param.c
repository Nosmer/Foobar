/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:48:55 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/29 13:39:33 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ms_get_param(char **environ, char *str)
{
	int		start;
	int		end;
	char	*tmp;

	start = 0;
	end = ft_strlen(str);
	while (*str)
	{
		if (*str == '$' || *str == '{')
			start++;
		if (*str == '}')
			end--;
		str++;
	}
	tmp = ft_strsub(str, start, end - start + 1);
	return (str);
}
