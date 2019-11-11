/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:00:30 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/11 16:31:39 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H
# include "./libft/libft.h"
# include <limits.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>

enum {ERR, USAGE};

typedef struct		s_opts
{
	int				rec;
	int				rev;
	int				time;
	int				all;
	int				lon;
}					t_opts;
/*
typedef struct		s_data
{
	blkcnt_t		st_blocks;
	mode_t			mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			size;
	dev_t			st_rdev;
	time_t			time;
	long			ntime;
	char			*name;
	char			path[PATH_MAX];
	struct s_data	*next;
	t_list			lst;
}					t_data;
*/
void				puterr_ls(char *s, int err);
int					get_dir(char *dir, t_opts *lst);
int					get_args(int argc, char **argv, t_opts *lst);
void				init_opts(t_opts *lst);
int					main(int argc, char *argv[]);
#endif
