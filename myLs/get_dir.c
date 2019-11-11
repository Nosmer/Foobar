/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:57:45 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/11 16:51:17 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int			get_path(char *path, char *ent, char *dir)
{
	ft_strncpy(path, dir, PATH_MAX);
	ft_strncat(path, "/", PATH_MAX);
	ft_strncat(path, ent, PATH_MAX);
	return (0);
}

int			get_stat(char *p, t_opts *lst, struct dirent *e)
{
	char			link[PATH_MAX + 1];
	struct stat		d;

	if (lstat(p, &d) == 0)
	{
		if (S_ISDIR(d.st_mode) && lst->rec == 1)
		{
			ft_putstr(p);
			ft_putchar('\n');
			get_dir(p, lst);
		}
		else if (S_ISREG(d.st_mode) || lst->rec == 0)
		{
			ft_putstr(e->d_name);
			ft_putchar('\n');
		}
		else if (S_ISLNK(d.st_mode))
		{
			if (readlink(p, link, PATH_MAX) != -1)
			{
				ft_putstr(e->d_name);
				ft_putstr(link);
				ft_putchar('\n');
			}
			else
				puterr_ls(p, ERR);
		}
		else
			puterr_ls(p, ERR);
	}
	return (0);
}

int			get_dir(char *dir, t_opts *lst)
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
			get_stat(path, lst, entry);
		}
		closedir(w_dir);
	}
	return (0);
}
