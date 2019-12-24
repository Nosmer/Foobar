/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:23:07 by bconsuel          #+#    #+#             */
/*   Updated: 2019/12/24 12:50:16 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define MINISHELL_BUFSIZE 1024;

char	*shell_read(void);
char	**shell_split(char *line);
int		shell_exec(char **args);

#endif
