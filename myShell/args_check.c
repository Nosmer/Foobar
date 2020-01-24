/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:48:40 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/24 15:00:49 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ms_get_line(char **environ, char *str, int len)
{
	char	*res;

	res = NULL;
	while (*environ)
	{
		if ((res = ft_strnstr(*environ, str, len)))
			break ;
		environ++;
	}
	return (res += len);
}

void		ms_get_tilde(char *args, char **environ)
{
	int		i;
	char	*tmp;

	i = 0;
	while (args[i] != '/' && args[i] != '\n')
		i++;
	if (i == 1)
		tmp = ms_get_line(environ, "HOME", 5);
	else if (i == 2 && args[1] == '+')
		tmp = ms_get_line(environ, "PWD", 4);
	else if (i == 2 && args[1] == '-')
		tmp = ms_get_line(environ, "OLDPWD", 7);
	else
		tmp = ms_get_user(environ, args, i);	
	args += i;
	args = ft_strjoin(tmp, args);
}

void		args_check(char **args, char **environ)
{
	while (*args)
	{
		if (*args[0] == '~')
			ms_get_tilde(*args, environ);
//		if (*args[0] == '$')
//			get_param(*args, environ);
		args++;
	}
}
