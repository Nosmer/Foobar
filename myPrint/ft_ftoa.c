/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:24:04 by bconsuel          #+#    #+#             */
/*   Updated: 2019/09/28 14:49:16 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fprintf.h"
#include <math.h>

static	double	ft_get_right(double f, int *res)
{
	double	mod;

	mod = 1;
	while ((int)(f /= 10) != 0 && (*res)++)
		mod *= 10;
	return (mod);
}

static	int	ft_handle_int(double *f, char **tmp, int *i, double mod)
{
	char	*s;

	s = *tmp;
	while ((int)*f != 0)
	{
		s[(*i)++] = (char)((*f / mod) + 48);
		*f -= (int)(*f / mod) * mod;
		mod /= 10;
	}
	return (0);
}

static	int	ft_handle_d(char **tmp, int *i, double f, int prec)
{
	int		j;
	int		k;
	char	*s;

	j = 0;
	f *= 10;
	s = *tmp;
	s[(*i)++] = '.';
	while (j++ < prec)
	{
		if ((int)f == 0)
		{
			s[(*i)++] = '0';
			continue;
		}
		k = ((int)f != 9) ? (int)(f + 0.01) : (int)f;
		s[(*i)++] = (char)(k + 48);
		f = (f - k) * 10;
	}
	return (0);
}

static	int	ft_inf(char **s)
{
	if (!(*s = malloc(sizeof(char) * 4)))
		return (0);
	*s = "inf";
	return (3);
}

int			ft_ftoa(t_listf *lst, double f, char **str)
{
	int		i;
	int		res;
	char	*tmp;
	double	right;
	int		neg;

	res = 1;
	neg = 0;
	i = 0;
	if (f == INFINITY)
		return (ft_inf(str));
	if (f < 0)
	{
		f *= -1;
		neg = 1;
	}
	right = ft_get_right(f, &res);
	res += lst->prec;
	if (!(tmp = malloc(sizeof(char) * (res + 1))))
		return (0);
	if (neg)
		tmp[i++] = '-';
	ft_handle_int(&f, &tmp, &i, right);
	ft_handle_d(&tmp, &i, f, lst->prec);
	tmp[--i] = '\0';
	*str = tmp;
	return (res);
}
