/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:57:45 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/09 14:42:58 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int			get_dir(char *dir, t_opts *lst)
{
	DIR				*w_dir;
	struct dirent	*entry;
	struct stat		info;
	char			path[PATH_MAX + 1];
	char			link[PATH_MAX + 1];

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
				entry = readdir(w_dir);
				continue;
			}
			ft_strncpy(path, dir, PATH_MAX);
			ft_strncat(path, "/", PATH_MAX);
			ft_strncat(path, entry->d_name, PATH_MAX);
			if (lstat(path, &info) == 0)
			{
				if (S_ISDIR(info.st_mode) && lst->rec == 1)
				{
					ft_putstr(path);
					ft_putchar('\n');
					get_dir(path, lst);
				}
				else if (S_ISREG(info.st_mode) || lst->rec == 0)
				{
					ft_putstr(entry->d_name);
					ft_putchar('\n');
				}
				else if (S_ISLNK(info.st_mode))
				{
					if (readlink(path, link, PATH_MAX) != -1)
					{
						ft_putstr(entry->d_name);
						ft_putstr(link);
						ft_putchar('\n');
					}
					else
						puterr_ls(path, ERR);
				}
				else
					puterr_ls(path, ERR);
			}
		}
		closedir(w_dir);
	}
	return (0);
}
