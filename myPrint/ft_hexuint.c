/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:18:10 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/23 12:58:11 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static void	ft_get_hex_ext(t_listf *lst, char *arr, int i)
{
	if (lst->type == 'x')
	{
		arr[i++] = 'x';
		arr[i] = '0';
	}
	else if (lst->type == 'X')
	{
		arr[i++] = 'X';
		arr[i] = '0';
	}
}

static int	ft_get_hex(t_listf *lst, char *arr, uintmax_t p)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	while (p != 0)
	{
		t = p % 16;
		if (t < 10)
			arr[i++] = t + 48;
		else
		{
			if (lst->type == 'x')
				arr[i++] = t + 87;
			if (lst->type == 'X')
				arr[i++] = t + 55;
		}
		p = p / 16;
	}
	if (HASH == '#')
	{
		ft_get_hex_ext(lst, arr, i);
		i += 2;
	}
	return (i);
}

static int	ft_put_hex(t_listf *lst, uintmax_t hex)
{
	char	arr[100];
	int		res;
	int		len;

	res = 0;
	len = ft_get_hex(lst, arr, hex);
	lst->wid = lst->wid - len + 1;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 0)
		res += ft_print(PRNT);
	ft_prnt_arr(arr, len);
	while (MINUS == '-' && (lst->wid)-- > 0)
		res += ft_print(' ');
	return (res + len);
}

int			ft_hexuint(t_listf *lst, void *hex)
{
	int		res;

	res = 0;
	if (lst->l)
		res += ft_put_hex(lst, (unsigned long)hex);
	else if (lst->ll)
		res += ft_put_hex(lst, (unsigned long long)hex);
	else if (lst->h)
		res += ft_put_hex(lst, (unsigned short)hex);
	else if (lst->hh)
		res += ft_put_hex(lst, (unsigned char)hex);
	else
		res += ft_put_hex(lst, (unsigned int)hex);
	return (res);
}
