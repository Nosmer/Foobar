/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:24:53 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/28 12:01:42 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Returns 0 if the letter is found, 1 otherwise
*/

int		isnew(char *s, int pos, char c)
{
	int		i;

	i = 0;
	while (i < pos)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (isnew(argv[1], i, argv[1][i]))
				write(1, &(argv[1][i]), 1);
			i++;
		}
		while (argv[2][j])
		{
			if (isnew(argv[1], i, argv[2][j])
				   	&& isnew(argv[2], j, argv[2][j]))
				write(1, &(argv[2][j]), 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
