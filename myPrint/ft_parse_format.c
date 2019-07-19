/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:37:46 by bconsuel          #+#    #+#             */
/*   Updated: 2019/07/19 16:54:07 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"
#include <stdio.h>

static int ft_isleng(int c)
{
	if ((c == 'h' && c + 1 == 'h') ||
			(c == 'l' && c + 1 == 'l'))
		return (2);
	if (c == 'h' || c == 'l')
		return (1);
	return (0);
}

static int	ft_isflag(int c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

static int	ft_istype(int c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'd' || c == 'i' || c == 'o' || c == 'u'
		   	|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int			ft_parse_format(char **format)
{
	/*
	 * read a string until we find any of the TYPE flags
	 */
	while (!ft_istype(**format))
	{
		if (ft_isflag(**format))
		{
			/* 
			 * while we find any of the FLAGS, write them down in the
			 * data structure (tbd)
			 */
		}
		if (ft_isdigit(**format))
		{
			/*
			 * here we read our width, write it down in the
			 * data structure (tbd)
			 */
		}
		if (**format == '.' && (*format)++)
		{
			/*
			 * here we read our precision, write it down in
			 * the data structure (tbd)
			 */
		}
		(*format)++;
	}
	return (0);
}
