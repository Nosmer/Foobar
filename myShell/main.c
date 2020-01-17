/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:22:30 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/17 15:46:59 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**args;
	int		status;
	char	**environ;

	status = 1;
	(void)argc;
	(void)argv;
	environ = strdd_cpy(envp);
	while (status != 0)
	{
		write(1, "$>", 2);
		line = shell_read();
		args = shell_split(line);
		status = shell_run(args, environ);
		free(line);
		free(args);
	}
	return (0);
}
