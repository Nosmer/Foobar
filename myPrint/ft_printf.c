/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:49:03 by bconsuel          #+#    #+#             */
/*   Updated: 2019/07/24 14:31:09 by bconsuel         ###   ########.fr       */
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
			count += ft_parse_format(&(format), ap);
		}
		else
			count += ft_print(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
