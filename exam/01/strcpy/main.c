/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:29:34 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/21 14:15:49 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}

#include <stdio.h>

int		main()
{
	char s1[] = "FooBar";
	char s2[] = "BarFoo";

	printf("%s\n", s2);
	ft_strcpy(s2, s1);
	printf("%s\n", s2);
	return (0);
}
