/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:57:45 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/12 15:21:51 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void		get_path(char *path, char *ent, char *dir)
{
	ft_strncpy(path, dir, PATH_MAX);
	ft_strncat(path, "/", PATH_MAX);
	ft_strncat(path, ent, PATH_MAX);
}

int			get_stat(char *path, char *e_name, t_opts *lst)
{
	char			link[PATH_MAX + 1];
	struct stat		data;

	if (lstat(path, &data) == 0)
	{
		if (S_ISDIR(data.st_mode) && lst->rec == 1)
		{
			ft_putstr(path);
			ft_putchar('\n');
			get_dir(path, lst);
		}
		else if (S_ISREG(data.st_mode) || lst->rec == 0)
		{
			ft_putstr(e_name);
			ft_putchar('\n');
		}
		else if (S_ISLNK(data.st_mode))
		{
			if (readlink(path, link, PATH_MAX) != -1)
			{
				ft_putstr(e_name);
				ft_putstr(link);
				ft_putchar('\n');
			}
			else
				puterr_ls(path, ERR);
		}
		else
			puterr_ls(path, ERR);
	}
	return (0);
}

int				get_dir(char *dir, t_opts *lst)
{
	DIR				*w_dir;
	struct dirent	*entry;
	char			path[PATH_MAX + 1];

	if ((w_dir = opendir(dir)) == NULL)
		puterr_ls(dir, ERR);
	else
	{
		while ((entry = readdir(w_dir)) != NULL)
		{
			if ((ft_strncmp(entry->d_name, ".", 1) == 0 ||
				ft_strncmp(entry->d_name, "..", 2) == 0))
			{
				if (lst->all == 1)
				{
					ft_putstr(entry->d_name);
					ft_putchar('\n');
				}
				continue;
			}
			get_path(path, entry->d_name, dir);
			get_stat(path, entry->d_name, lst);
		}
		closedir(w_dir);
	}
	return (0);
}
