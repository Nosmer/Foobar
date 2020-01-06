/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:23:07 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/06 16:45:34 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define MS_BUFSIZE 1024;
# define MS_TOK_BUFSIZE 64;
# define MS_TOK_DELIM " -\n\a\r\t";

char	*shell_read(void);
char	**shell_split(char *line);
int		shell_exec(char **args);

#endif
