/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:12:16 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/11 16:20:43 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		main(int argc, char *argv[])
{
	t_opts	opts;
//	t_data	data;

	init_opts(&opts);
	get_args(argc, argv, &opts);
	return (0);
}
