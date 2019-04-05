/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:19:53 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/05 10:52:31 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int res;
	int i;

	res = 1;
	i = 1;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb == 2)
		return (2);
	while (i <= nb)
	{
		res = res * i;
		i++;
	}
	return (res);
}
