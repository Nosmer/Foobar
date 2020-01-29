/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:52:56 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/29 13:32:23 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_avail(char *str)
{
	int		len;

	len = ft_strlen(str) - 1;
	if (access(str, F_OK) != 0)
	{
		if (str[len] == '/')
		{
			ft_putstr_fd("minishell: no such file or directory: ", 2);
			ft_putendl_fd(str, 2);
		}
		else
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putendl_fd(str, 2);
		}
		return (1);
	}
	return (0);
}

int			ms_args_check(char **args, char **environ)
{
	int		i;

	i = 0;
	if (args[0] == NULL)
		return (1);
	if (check_avail(args[0]) != 0)
		return (1);
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
	return (0);
}
