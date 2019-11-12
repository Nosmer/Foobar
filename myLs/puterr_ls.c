/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:27:38 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/12 15:12:23 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void		puterr_ls(char *s, int err)
{
	if (err == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*s, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ./ft_ls [-Ralrt] [file ...]", 2);
	}
	else if (err == ERR)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	if (err == USAGE || err == CRIT)
		exit(EXIT_FAILURE);
}
