/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:00:30 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/09 12:50:45 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>

enum {ERR, USAGE};

typedef struct	s_opts
{
	int			rec;
	int			rev;
	int			time;
	int			all;
	int			lon;
}				t_opts;

void			puterr_ls(char *s, int err);
int				get_dir(char *dir, t_opts *lst);
int				get_args(int argc, char **argv, t_opts *lst);
void			init_list(t_opts *lst);
int				main(int argc, char *argv[]);
#endif
