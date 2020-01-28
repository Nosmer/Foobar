/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:13:55 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/28 19:23:23 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_exec_name(char *str, int mode)
{
/*
** ERROR HERE
*/
	int		i;
	char	*name;

	i = 0;
	while (str[i])
	{
		if (mode == 0)
		{
			if (str[i] == '/')
				name = &str[i];
		}
		else
		{
			if (str[i] == '/' && ft_isprint(str[i + 1]))
				name = &str[i];
		}
		i++;
	}
	++name;
	return (name);
}

void		check_avail(char *str)
{
	int		len;

	len = ft_strlen(str) - 1;
	if (access(str, F_OK) != 0)
	{
		if (str[len] == '/')
		{
			ft_putstr_fd("minishell: no such file or directory: ", 2);
			ft_putendl_fd(get_exec_name(str, 1), 2);
		}
		else
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putendl_fd(get_exec_name(str, 0), 2);
		}
		exit(EXIT_FAILURE);
	}
}

int			shell_exec(char **args, char **environ)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		check_avail(args[0]);
		if (execve(args[0], args, environ) == -1)
			ft_putstr_fd("minishell", 2);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_putendl_fd("minishell", 2);
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

int			shell_run(char **args, char **environ)
{
	int		i;

	i = 0;
	if (args[0] == NULL)
		return (1);
	if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	args_check(args, environ);
/*	while (i < num_builtin())
**	{
**		if (ft_strcmp(args[0], builtin_s[i]) == 0)
**			return (*builtin_f[i](args, environ));
**		i++;
**	}
*/
	return (shell_exec(args, environ));
}
