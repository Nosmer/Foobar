/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:57:45 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/06 14:56:45 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		get_dir(char *dir, t_opts *lst)
{
	DIR				*w_dir;
	struct dirent	*entry;

	if ((w_dir = opendir(dir)) == NULL)
		ft_puterr_ls(1, dir, strerror(errno));
	else
	{
		while ((entry = readdir(w_dir)) != NULL)
		{
			if ((ft_strncmp(entry->d_name, ".", 1) == 0 ||
				ft_strncmp(entry->d_name, "..", 2) == 0) &&
				lst->all != 1)
				continue;
			else
			{
				ft_putstr(entry->d_name);
				ft_putchar('\n');
			}
		}
		closedir(w_dir);
	}
	return (0);
}
