/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:48:55 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/29 17:42:35 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		expand_brace(char *str)
{
}

char		*ms_get_param(char *str, char **environ)
{
	int		start;
	int		end;
	char	*temp;

	start = 0;
	end = ft_strlen(str);
	if (*str == '$')
		str++;
	if (*str == '{')
		temp = expand_brace(str);
	else
		temp = expand_arg(str);
printf("testing: %s\n", str);
	return (str);
}
