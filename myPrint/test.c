#include "fprintf.h"
#include <stdio.h>

int		ft_test(const char * format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (ft_isdigit(*format))
			ft_putchar('y');
		else
			ft_putchar('n');
//		printf("Pointer: %p\n", format);
//		printf("String: %s\n", format);
		format++;
	}
	return (0);
}

int		main()
{
  	char *s = "FooBar";
/*
	while (*s)
	{
		if (ft_isdigit(*s))
			ft_putchar(*s);
		else
			ft_putchar('0');
		s++;
	}
*/
	ft_printf("Foo%0#33.55sBar\n");
//	ft_test("Foo5Bar\n");
	return (0);
}
