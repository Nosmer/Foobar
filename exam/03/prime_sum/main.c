/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:59:42 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/29 13:29:33 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 8 && *str <= 14))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int		isprime(int	n)
{
	int		i;

	i = 2;
	while (i <= n - 1)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	if (i == n)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		num;
	int		res;

	i = 2;
	res = 0;
	if (argc == 2)
		num = ft_atoi(argv[1]);
	if (num > 0)
	{
		while (i <= num)
		{
			if (isprime(i))
				res += i;
			i++;
		}
	}
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
