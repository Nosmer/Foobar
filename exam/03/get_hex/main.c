/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:39:46 by bconsuel          #+#    #+#             */
/*   Updated: 2019/12/02 14:58:01 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	get_hex(int hex)
{
	if (hex >= 16)
		get_hex(hex/16);
	hex = hex % 16;
	if (hex < 10)
		hex += '0';
	else
		hex += 'a' - 10;
	write(1, &hex, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		get_hex(atoi(argv[1]));
	printf("\n");
	return (0);
}
