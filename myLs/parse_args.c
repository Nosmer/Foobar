/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:05:54 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/05 16:24:50 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		proc_dir(char *dir)
{
	struct dirent	entr;
	struct dirent	*entr_ptr;
	DIR				*wrk_dir;
	int				retval;
	char			path_name[PATH_MAX + 1];

	dir = NULL;
	entrPtr = NULL;
	retval = 0;
	if ((dir = opendir(dir)) == NULL)
		ft_puterr(1, dir, strerror(errno));
	retval = readdir(wrk_dir, &entr, &entr_ptr);
	while (entr_ptr != NULL)
	{
		if ((ft_strncmp(entr.d_name, ".", PATH_MAX) == 0) ||
			(ft_strncmp(entr.d_name, "..", PATH_MAX) == 0))
		{
			retval = readdir(wrk_dir, &entr, &entr_ptr);
			continue;
		}
		do_smth_to(retval);
	}
	(void)closedir(wrk_dir);
	return (0);
}

int		parse_args(int argc, char **argv, t_opts *lst)
{
	int		i;
	size_t	opt;

	i = 1;
	opt = 0;
	while (i < argc)
	{
		if (argv[i][opt] == '-')
		{
			while (argv[i][opt])
			{
				if (argv[i][opt] == 'l')
					lst->lon = 1;
				if (argv[i][opt] == 'R')
					lst->rec = 1;
				if (argv[i][opt] == 'a')
					lst->all = 1;
				if (argv[i][opt] == 'r')
					lst->rev = 1;
				if (argv[i][opt] == 't')
					lst->time = 1;
				opt++;
			}
		}
		else
			proc_dir(argv[i]);
		i++;
		opt = 0;
	}
	return (0);
}
