/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:46:06 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/09 13:42:54 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		parse_opts(char *str, t_opts *lst)
{
	size_t	opt;

	opt = 0;
	while (str[++opt])
	{
		if (str[opt] == 'l')
			lst->lon = 1;
		else if (str[opt] == 'R')
			lst->rec = 1;
		else if (str[opt] == 'a')
			lst->all = 1;
		else if (str[opt] == 'r')
			lst->rev = 1;
		else if (str[opt] == 't')
			lst->time = 1;
		else
			puterr_ls(&str[opt], USAGE);
	}
	return (0);
}

int		get_args(int argc, char **argv, t_opts *lst)
{
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && flag == 0)
			parse_opts(argv[i], lst);
		else
		{
			get_dir(argv[i], lst);
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		get_dir(".", lst);
	return (0);
}
