/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:26:57 by bconsuel          #+#    #+#             */
/*   Updated: 2019/07/19 15:36:44 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPRINTF_H
# define FPRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(char *format, ...);
int		ft_parse_format(char **format);
# endif
