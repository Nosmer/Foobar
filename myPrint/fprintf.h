/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:26:57 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/03 13:54:23 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPRINTF_H
# define FPRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# define PRNT	(lst->flag)[0]
# define HASH	(lst->flag)[1]
# define ZERO	(lst->flag)[2]
# define MINUS	(lst->flag)[3]
# define PLUS	(lst->flag)[4]
# define SPACE	(lst->flag)[5]

typedef	struct	s_listf
{
	char		*flag;
	short		wid;
	short		prec;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			lll;
	char		type;
}				t_listf;

int				ft_printf(char *format, ...);
int				ft_parse_format(char **format, va_list ap);
int				ft_handle_type(t_listf *lst, va_list ap);
int				ft_percent(t_listf *lst);
int				ft_char(t_listf *lst, int c);
int				ft_string(t_listf *lst, void *s);
int				ft_pointer(t_listf *lst, void *p);
int				ft_int(t_listf *lst, void *di);
//int				ft_uint(t_listf *lst);
//int				ft_duint(t_listf *lst);
//int				ft_hexuint(t_listf *lst);
//int				ft_double(t_listf *lst);
int				ft_print(int c);
void			test_func(t_listf *lst);
# endif
