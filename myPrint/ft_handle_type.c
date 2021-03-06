/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:25:32 by bconsuel          #+#    #+#             */
/*   Updated: 2019/09/28 13:36:48 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

/*
** Calls different functions depending on spec field of
** lst data structure.
 */

int		ft_handle_type(t_listf *lst, va_list ap)
{
	int		len;

	len = 0;
	if (lst->type == '%')
		len = ft_char(lst, '%');
	else if (lst->type == 'c')
		len = ft_char(lst, va_arg(ap, int));
	else if (lst->type == 's')
		len = ft_string(lst, va_arg(ap, char *));
	else if (lst->type == 'p')
		len = ft_pointer(lst, va_arg(ap, void *));
	else if (lst->type == 'd' || lst->type == 'i')
		len = ft_int(lst, va_arg(ap, void *));
	else if (lst->type == 'o')
		len = ft_int_oct(lst, va_arg(ap, void*));
	else if (lst->type == 'u')
		len = ft_uint(lst, va_arg(ap, void *));
	else if (lst->type == 'x' || lst->type == 'X')
		len = ft_hexuint(lst, va_arg(ap, void *));
	else if (lst->type == 'f' && !(lst->ell))
		len = ft_double_f(lst, va_arg(ap, double));
//	else if (lst->type == 'f' && lst->ell)
//		len = ft_double_lf(lst, va_arg(ap, long double));
	ft_strdel(&(lst->flag));
	return (len);
}
