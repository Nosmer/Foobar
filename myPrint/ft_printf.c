/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:49:03 by bconsuel          #+#    #+#             */
/*   Updated: 2019/07/15 13:38:12 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"
#include <stdio.h>

int		ft_printf(const char * restrict format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
			format++;
			parse_format(*format);
		}
		format++;
	}
	va_end(ap);
	return (0);
}

int main()
{
	int		a;

	a = 5;
	ft_printf("Foo%dBar\n", a);
	printf("Foo%dBar\n", a);
	return (0);
}
