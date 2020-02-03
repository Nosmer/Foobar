/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:13:55 by bconsuel          #+#    #+#             */
/*   Updated: 2020/02/03 17:26:33 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				shell_exec(char *cmd, char **args, char **environ)
{
	pid_t		pid;

	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid == 0)
		execve(cmd, args, environ);
	else if (pid < 0)
	{
		ft_putendl_fd("minishell: fork() failure", 2);
		free(cmd);
		return (1);
	}
	wait(&pid);
	if (cmd)
		free(cmd);
	return (1);
}

int				ms_isbuiltin(char **args, char **environ)
{
	if (ft_strequ(args[0], "exit"))
		return (0);
	if (ft_strequ(args[0], "echo"))
		return (ms_echo(args + 1));
	if (ft_strequ(args[0], "cd"))
		return (ms_cd(args + 1));
	if (ft_strequ(args[0]), "setenv")
		return (ms_setenv(args + 1));
	if (ft_strequ(args[0]), "unsetenv")
		return (ms_unsetenv(args + 1));
	if (ft_strequ(args[0]), "env")
	{
		strdd_print(environ);
		return (0);
	}
	return (0);
}

int				ms_isexec(char *tmp, struct stat f, char **args)
{
	if (f.st_mode & S_IFREG)
	{
		if (f.st_mode & S_IXUSR)
			return (shell_exec(tmp, command));
		else
		{
			ft_putstr_fd("minishell: permission denied: ", 2);
			ft_putendl_fd(tmp, 2);
			return (1);
		}
	}
	free(tmp);
	return (1);
}

int				ms_isbin(char **args)
{
	int			i;
	char		*tmp;
	char		**path;
	struct stat	f;

	path = ft_strsplit(ms_getenv("PATH"), ":");
	i = -1;
	while (path && path[++i])
	{
		if (ms_startw(args[0], path[i]))
			tmp = ft_strdup(args[0]);
		else
			tmp = ms_make_path(path[i], args[0]);
		if (lstat(tmp, &f) == -1)
			free(tmp);
		else
		{
			strdd_free(path);
			return (ms_isexec(path, f, args));
		}
	}
	strdd_free(path);
	return (1);
}

int				shell_run(char **args, char **environ)
{
	struct stat	f;
	int			flag;

	if ((flag = ms_isbuiltin(args) == 1) || ms_isbin(args))
		return (1);
	if (flag < 0)
		return (0);
	if (lstat(args[0], &f) != -1)
	{
		if (f.st_mode & S_IFDIR)
		{
			ms_edit_dir(args[0], 0);
			return (1);
		}
		else if (f.st_mode & S_IXUSR)
			return (shell_exec(args[0], args, environ));
	}
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(args[0], 2);
	return (1);
}
