/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:22:30 by bconsuel          #+#    #+#             */
/*   Updated: 2020/02/03 16:30:47 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Main of a minishell. First it copies environment variables,
** then in read_line reads user input and stores it in line.
** After that - splits the line into arguments by a delimiter
** from minishell.h and launches them with shell_run.
*/

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**args;
	int		status;
	char	**environ;

	status = 1;
	(void)argc;
	(void)argv;
	while (status != 0)
	{
		environ = strdd_cpy(envp);
		write(1, "$> ", 3);
		signal(SIGINT, signal_handler);
		line = shell_read();
		args = shell_split(line);
		status = shell_run(args, environ);
		free(line);
		free(args);
	}
	strdd_free(environ);
	return (0);
}
