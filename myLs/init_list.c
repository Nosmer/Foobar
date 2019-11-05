/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:10:44 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/05 13:41:51 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void		init_list(t_opts *lst)
{
	lst->rec = 0;
	lst->rev = 0;
	lst->time = 0;
	lst->all = 0;
	lst->lon = 0;
}