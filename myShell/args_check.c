/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:48:40 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/24 16:01:31 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check out getpwnam()
*/

#include "minishell.h"

char		*ms_get_line(char **environ, char *str)
{
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = NULL;
	while (*environ)
	{
		if ((res = ft_strnstr(*environ, str, len)))
			break ;
		environ++;
	}
	if (res[len] == '=')
		res++;
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
		tmp = ms_get_line(environ, "HOME");
	else if (i == 2 && args[1] == '+')
		tmp = ms_get_line(environ, "PWD");
	else if (i == 2 && args[1] == '-')
		tmp = ms_get_line(environ, "OLDPWD");
//	else
//	GET USER
//		tmp = ms_get_user(environ, args, i);	
	args += i;
	args = ft_strjoin(tmp, args);
printf("%s\n", args);
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
