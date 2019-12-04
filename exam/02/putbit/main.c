/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:23:58 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/27 13:04:30 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char		reverse_bits(unsigned char octet)
{
	unsigned char	r;
	int				i;

	i = 8;
	while (i--)
	{
		r = (r << 1) | (octet & 1);
		octet >>= 1;
	}
	return (r);
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

void			print_bits(unsigned char octet)
{
	int		i;

	i = 128;
	while (i > 0)
	{
		if (octet & i)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i >>= 1;
	}
}

int				main()
{
	char	i;

	i = 55;
	print_bits(i);
	i = swap_bits(i);
	write(1, "\n", 1);
	print_bits(i);
	write(1, "\n", 1);
	i = reverse_bits(i);
	print_bits(i);
	write(1, "\n", 1);
	return (0);
}
