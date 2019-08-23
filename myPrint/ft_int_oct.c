/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:34:44 by bconsuel          #+#    #+#             */
/*   Updated: 2019/08/23 11:43:00 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"

static void	ft_prnt_oct(int *octal, int i)
{
	int		j;

	j = i - 1;
	while (j >= 0)
	{
		ft_putnbr(octal[j]);
		j--;
	}
}

static int	ft_get_oct(int *octal, uintmax_t oct)
{
	uintmax_t	temp;
	int			i;

	i = 0;
	temp = oct;
	while (temp)
	{
		octal[i] = temp % 8;
		temp = temp / 8;
		i++;
	}
	return (i);
}

static int	ft_put_oct(t_listf *lst, uintmax_t oct)
{
	int		res;
	int		len;
	int		octal[100];

	res = 0;
	len = ft_get_oct(octal, oct);
	lst->wid = lst->wid - len;
	if (ZERO == '0')
		PRNT = ZERO;
	while (MINUS != '-' && (lst->wid)-- > 0)
		res += ft_print(PRNT);
	if (HASH == '#' && oct != 0)
		res += ft_print('0');
	ft_prnt_oct(octal, len);
	while (MINUS == '-' && (lst->wid)-- > 0)
		res += ft_print(' ');
	return (res += len);
}

int			ft_int_oct(t_listf *lst, void *oct)
{
	int		res;

	res = 0;
	if (lst->l)
		res += ft_put_oct(lst, (unsigned long)oct);
	else if (lst->ll)
		res += ft_put_oct(lst, (unsigned long long)oct);
	else if (lst->h)
		res += ft_put_oct(lst, (unsigned short)oct);
	else if (lst->hh)
		res += ft_put_oct(lst, (unsigned char)oct);
	else
		res += ft_put_oct(lst, (unsigned int)oct);
	return (res);
}
