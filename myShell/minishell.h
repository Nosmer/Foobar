/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:23:07 by bconsuel          #+#    #+#             */
/*   Updated: 2020/02/03 15:22:37 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "./lib/libft.h"
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <dirent.h>
# define MS_BUFSIZE 1024
# define MS_TOK_BUFSIZE 64
# define MS_TOK_DELIM " \n\a\r\t\v\f"

enum {DIRE, COMM};

char	*shell_read(void);
char	**shell_split(char *line);
int		shell_run(char **args, char **environ);
char	*get_token(char *s, const char *delim);
void	ft_reallocate(char **tokens, int bufsize);
char	**strdd_cpy(char **source);
void	strdd_print(char **source);
void	strdd_free(char **source);
char	*ms_get_tilde(char *str, char **environ);
char	*ms_get_param(char *str, char **environ);
char	*ms_make_path(char *s1, char *s2);
void	signal_handler(int signo);
void	proc_signal_handler(int signo);

#endif
