/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:37:46 by bconsuel          #+#    #+#             */
/*   Updated: 2019/07/22 15:05:19 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"
#include <stdio.h>

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
		   	|| c == 'x' || c == 'X' || c == 'f')
		return (1);
	return (0);
}

static	void	ft_get_hl(char **f, t_list *lst)
{

}

int				ft_get_num(char **f)
{
	int		i;
	int		res;

	i = 0;
	while ((*f)[i] >= '0' && (*f)[i] <= '9')
	{
		res = res * 10 + (*f)[i] - '0';
		i++;
	}
//	*f = &(*f)[i];
	return (res * 1);
}

static	void	ft_put_flag(char **f, t_list *lst)
{
	if (**f == '#')
		(lst->flag)[0] = '#';
	else if (**f == '0')
		(lst->flag)[1] = '0';
	else if (**f == '-')
		(lst->flag)[2] = '-';
	else if (**f == '+')
		(lst->flag)[3] = '+';
	else if (**f == ' ')
		(lst->flag)[4] = ' ';
}

static	void	ft_init(t_list *lst)
{
	lst->flag = ft_strdup("*****");
	lst->wid = 0; /* -1 */
	lst->prec = 0; /* -1 */
	lst->h = 0;
	lst->hh = 0;
	lst->l = 0;
	lst->ll = 0;
}

/*
** Reads a string passed as parameter and writes down all
** found format specifiers in freshly initialised data structure.
** Uses **format because it needs to traverse the string while
** reading it.
 */

int			ft_parse_format(char **format)
{
	t_list	lst;

	ft_init(&lst);
	while (!ft_istype(**format))
	{
		if (ft_isflag(**format))
			ft_put_flag(format, lst);
		if (ft_isdigit(**format))
			lst.wid = ft_get_num(format);
		if (**format == '.' && (*format)++)
			lst.prec = ft_get_num(format);
		if (**format == 'h' || **format == 'l')
			ft_get_hl(format, lst);
		(*format)++;
	}
	lst.spec = **format;
	return (0);
}
