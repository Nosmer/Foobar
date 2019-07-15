/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:25:01 by bconsuel          #+#    #+#             */
/*   Updated: 2019/07/15 14:48:48 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

int		get_flags(char *c)
{
	int		i;

	i = 0;
	if (*c == '#')
		//do_stuff
	if (*c == ' ')
		//do_stuff
	if (*c == '0')
		//do_stuff
	if (*c == '+')
		//do_stuff
	if (*c == '-')
		//do_stuff
	return (i);
}

int		get_type(char *c)
{
	int		i;

	i = 0;
	if (*c == 'c' || *c == 's' || *c == 'p' || *c == 'd' || *c == 'i'
			|| *c == 'o' || *c == 'u' || *c == 'x' || *c == 'X')
		i = 1;
	return (i);
}

int		parse_format(char *c)
{
	int i;

	i = 0;
	while (!get_type(c))
	{
		if (get_flags(c))
			c++;
		if (get_width(c))
			c++;
		if (get_precision(c))
			c++;
		if (get_size(c))
			c++;
		c++;
	}
	return (i);
}
