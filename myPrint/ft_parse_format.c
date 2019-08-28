/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:37:46 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/28 12:04:49 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static int	ft_isflag(int c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

static int	ft_istype(int c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'o' || c == 'u'
		   	|| c == 'x' || c == 'X' || c == 'f')
		return (1);
	return (0);
}

static	void	ft_get_hl(char **f, t_listf *lst)
{
	if (**f == 'h' && !(lst->h) && !(lst->hh))
	{
		if ((*f)[0] == (*f)[1])
			lst->hh = 1;
		else
			lst->h = 1;
	}
	if (**f == 'l' && !(lst->l) && !(lst->ll))
	{
		if ((*f)[0] == (*f)[1])
			lst->ll = 1;
		else
			lst->l = 1;
	}
	if (**f == 'L')
		lst->ell = 1;
}

int				ft_get_num(char **f)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while ((*f)[i] >= '0' && (*f)[i] <= '9')
	{
		res = res * 10 + (*f)[i] - '0';
		i++;
	}
	return (res * 1);
}

static	void	ft_put_flag(char **f, t_listf *lst)
{
	if (**f == '#')
		HASH = '#';
	else if (**f == '0')
		ZERO = '0';
	else if (**f == '-')
		MINUS = '-';
	else if (**f == '+')
		PLUS = '+';
	else if (**f == ' ')
		SPACE = ' ';
}

static	void	ft_init(t_listf *lst)
{
	lst->flag = ft_strdup(" *****");
	lst->wid = -1;
	lst->prec = -1;
	lst->h = 0;
	lst->hh = 0;
	lst->l = 0;
	lst->ll = 0;
	lst->ell = 0;
}

/* Reads a string passed as parameter and writes down all
** found format specifiers in freshly initialised data structure.
** Uses **format because it needs to traverse the string while
** checking for modifiers.
 */

int			ft_parse_format(char **format, va_list ap)
{
	t_listf	lst;

	ft_init(&lst);
	while (!ft_istype(**format))
	{
		if (ft_isflag(**format) && lst.wid == -1 && lst.prec == -1)
			ft_put_flag(format, &lst);
		if (ft_isdigit(**format) && lst.wid == -1 && lst.prec == -1)
			lst.wid = ft_get_num(format);
		if (**format == '.' && (*format)++)
			lst.prec = ft_get_num(format);
		if (**format == 'h' || **format == 'l' || **format == 'L')
			ft_get_hl(format, &lst);
		(*format)++;
	}
	lst.type = **format;
	return (ft_handle_type(&lst, ap));
}
