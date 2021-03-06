/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:02:50 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/06 14:48:05 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	err_char(char c)
{
	write(2, &c, 1);
}

static void	err_str(char *s)
{
	while (*s)
	{
		err_char(*s);
		s++;
	}
}

void		ft_puterr_ls(int nbr, char *dir, char *err)
{
	err_str("ft_ls: ");
	if (nbr == 1)
	{
		err_str(dir);
		err_str(": ");
		err_str(err);
		err_char('\n');
	}
	else
		err_str("tbd");
}
