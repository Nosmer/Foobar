/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:50:46 by bconsuel          #+#    #+#             */
/*   Updated: 2019/04/08 10:33:33 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int res;

	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	res = nb * ft_recursive_factorial(nb - 1);
	return (res);
}
