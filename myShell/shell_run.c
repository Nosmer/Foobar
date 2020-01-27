/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:13:55 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/27 16:49:15 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			shell_exec(char **args, char **environ)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			ft_putstr_fd("minishell: command not found:", 2);
			ft_putendl_fd(args[0], 2);
		}
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
	if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	args_check(args, environ);
	if (args[0] == NULL)
		return (1);
/*	while (i < num_builtin())
**	{
**		if (ft_strcmp(args[0], builtin_s[i]) == 0)
**			return (*builtin_f[i](args, environ));
**		i++;
**	}
*/
	return (shell_exec(args, environ));
}
