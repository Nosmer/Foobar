/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:26:57 by bconsuel          #+#    #+#             */
/*   Updated: 2019/07/22 14:09:59 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPRINTF_H
# define FPRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

typedef	struct	s_list
{
	char		*flag;
	short		wid;
	short		prec;
	int			h;
	int			hh;
	int			l;
	int			ll;
	char		spec;
}				t_list;

int				ft_printf(char *format, ...);
int				ft_parse_format(char **format);
# endif
