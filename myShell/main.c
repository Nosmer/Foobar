/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:22:30 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/14 15:33:18 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **environ)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	(void)argc;
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
