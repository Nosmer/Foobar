#include "fprintf.h"
#include <stdio.h>

void	get_hex(size_t s)
{
	char	hex[100];
	int		i;
	int		j;
	int		t;

	i = 0;
	t = 0;
	while (s != 0)
	{
		t = s % 16;
		if (t < 10)
			hex[i++] = t + 48;
		else
			hex[i++] = t + 87; /* 55 */
		s = s / 16;
	}
	j = i - 1;
	while (j >= 0)
	{
		ft_putchar(hex[j]);
		j--;
	}
	ft_putchar('\n');
}

int		main()
{
	char	*s = "FooBar";
	int		i = 0;
	int		j = 0;
	int		t = 345678;
	double	d = 654.654;
	char	c = 'a';
//	ft_printf("Foo%-3.3sBar\n", "foobar");
	i = printf("pr: %f\n", d);
	j = ft_printf("my: %f\n", d);
	printf("i: %d, j: %d\n", i, j);
	return (0);
}
