/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:04:30 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/22 15:23:00 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_getchr(char *s, char c)
{
	int		i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}


int		main(int argc, char **argv)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			p = ft_getchr(argv[2], argv[1][i]);
			if (p != 0)
				write(1, &(argv[2][p]), 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
