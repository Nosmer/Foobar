/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:13:24 by bconsuel          #+#    #+#             */
/*   Updated: 2019/11/28 14:30:40 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	char	t;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		len--;
		t = str[i];
		str[i] = str[len];
		str[len] = t;
		i++;
	}
	return (str);
}

int		main()
{
	char c[] = "FooBar";
	char *s;

	puts(c);
	s = ft_strrev(c);
	printf("%s\n", s);
	return (0);
}
