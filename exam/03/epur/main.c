/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:51:25 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/29 14:18:43 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	int		flag;

	i = 0;
	flag = -1;
	if (argc == 2)
	{
		while (argv[1][i] == ' '|| argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flag = 0;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (flag == 0)
					write(1, " ", 1);
				flag = 1;
				write(1, &argv[1][i] , 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
