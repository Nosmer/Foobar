/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:46:06 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/06 15:43:28 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		parse_opts(char *str, size_t opt, t_opts *lst)
{
	while (str[opt])
	{
		if (str[opt] == 'l')
			lst->lon = 1;
		if (str[opt] == 'R')
			lst->rec = 1;
		if (str[opt] == 'a')
			lst->all = 1;
		if (str[opt] == 'r')
			lst->rev = 1;
		if (str[opt] == 't')
			lst->time = 1;
		opt++;
	}
	return (0);
}

int		get_args(int argc, char **argv, t_opts *lst)
{
	int		i;
	size_t	opt;
	int		flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		opt = 0;
		if (argv[i][opt] == '-')
			parse_opts(argv[i], opt, lst);
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
