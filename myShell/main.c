/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:22:30 by bconsuel          #+#    #+#             */
/*   Updated: 2019/12/24 11:54:29 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status != 0)
	{
		write(1, "$>", 2);
		line = shell_read();
		args = shell_split(line);
		status = shell_exec(args);

		free(line);
		free(args);
	}
	return (0);
}
