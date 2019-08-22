/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:19:53 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/22 13:55:09 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static int	put_wchar_str(t_listf *lst, wchar_t *w)
{
	int		res;

	res = 0;
	if (w == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*w && lst->prec--)
	{
		res += ft_print(*w);
		w++;
	}
	return (res);
}

static int	put_string(t_listf *lst, char *s)
{
	int		res;

	res = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*s && (lst->prec)--)
	{
		res += ft_print(*s);
		s++;
	}
	return (res);
}

int			ft_string(t_listf *lst, void *s)
{
	int		res;

	res = 0;
	lst->wid = lst->wid - ft_strlen(s);
	while (MINUS != '-' && (lst->wid)-- > 0)
		res += ft_print(' ');
	if (lst->l)
		res += put_wchar_str(lst, (wchar_t *)s);
	else
		res += put_string(lst, (char *)s);
	while (MINUS == '-' && (lst->wid)-- > 0)
		res += ft_print(' ');
	return (res);
}
