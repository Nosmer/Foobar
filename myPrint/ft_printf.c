/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:49:03 by bconsuel          #+#    #+#             */
/*   Updated: 2019/07/19 16:36:49 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

int		ft_printf(char *format, ...)
{
	va_list ap;
	size_t	count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_parse_format(&(format));
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
