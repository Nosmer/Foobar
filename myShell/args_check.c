/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:48:40 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/28 19:13:22 by bconsuel         ###   ########.fr       */
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
		len++;
	return (res += len);
}

char		*ms_get_param(char *str, char **environ)
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

char		*ms_get_tilde(char *str, char **environ)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '/' && str[i] != '\0')
		i++;
	if (i == 1)
		tmp = ms_get_line(environ, "HOME");
	else if (i == 2 && str[1] == '+')
		tmp = ms_get_line(environ, "PWD");
	else if (i == 2 && str[1] == '-')
		tmp = ms_get_line(environ, "OLDPWD");
	str += i;
	str = ft_strjoin(tmp, str);
	return (str);
}

void		args_check(char **args, char **environ)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '~')
			args[i] = ms_get_tilde(args[i], environ);
		else if (args[i][0] == '$')
			args[i] = ms_get_param(args[i], environ);
		else if (i == 0 && ft_strcmp(args[i], &args[i][0]) == 0)
			args[i] = ft_strjoin("/bin/", &args[i][0]);
		i++;
	}
}
