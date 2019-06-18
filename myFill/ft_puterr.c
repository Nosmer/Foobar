/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 13:40:06 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/18 13:39:25 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Convenienlty exits the program is we encounter an error.
** You should pass 1 only to check the correct amount of input,
** 0 for everything else.
*/

void	ft_puterr(int c)
{
	if (c == 0)
		ft_putstr_fd("error\n", 1);
	if (c == 1)
		ft_putstr_fd("usage: fillit [input_file]\n", 1);
	exit(1);
}
