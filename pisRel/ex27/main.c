/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:02:59 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/04 13:21:06 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#define BUF_SIZE 16

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		close(fd);
	}
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}
