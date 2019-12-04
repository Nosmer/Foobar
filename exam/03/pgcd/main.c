/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:02:01 by bconsuel          #+#    #+#             */
/*   Updated: 2019/12/02 14:25:29 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		i;
	int		x;
	int		y;
	int		gcd;

	i = 1;
	if (argc == 3)
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);	
		while (i <= x && i <= y)
		{
			if ((x % i == 0) && (y % i == 0))
				gcd = i;
			i++;
		}
		printf("%d", gcd);
	}
	printf("\n");
	return (0);
}
