#include "fprintf.h"
#include <stdio.h>

void		test_func(t_listf *lst)
{
	char *c = lst->flag;

	ft_putchar('\n');
	while (*c)
	{
		ft_putchar(*c);
		c++;
	}
	ft_putchar('\n');
	ft_putnbr(lst->wid);
	ft_putchar('\n');
	ft_putnbr(lst->prec);
	ft_putchar('\n');
	ft_putchar(lst->type);
	ft_putchar('\n');
	ft_putnbr(lst->h);
	ft_putchar('\n');
	ft_putnbr(lst->hh);
	ft_putchar('\n');
	ft_putnbr(lst->l);
	ft_putchar('\n');
	ft_putnbr(lst->ll);
	ft_putchar('\n');
}
