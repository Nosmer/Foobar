/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:32:45 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/07 15:15:37 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include <stdio.h>
/*
 * Use only test_store with this!!!
 */
int main(int argc, char **argv)
{
	t_board	*test;
	int		fd;
	int		ret;
	char	buf[22];

	test->nb_tet = 0;
	if (!(test->tets = malloc(sizeof(char *))))
	test->map = NULL;
	if (!(fd = open(argv[1], O_RDONLY)))
		ft_puterr(0);
	while ((ret = read(fd, buf, 21)))
	{
		ft_store(test, buf);
	}
	return (0);
}
