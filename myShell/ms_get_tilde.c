/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:48:40 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/29 13:14:49 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check out getpwnam()
*/

#include "minishell.h"

char		*ms_get_line(char **environ, char *str)
{
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = NULL;
	while (*environ)
	{
		if ((res = ft_strnstr(*environ, str, len)))
			break ;
		environ++;
	}
	if (res[len] == '=')
		len++;
	return (res += len);
}

char		*ms_get_tilde(char *str, char **environ)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '/' && str[i] != '\0')
		i++;
	if (i == 1)
		tmp = ms_get_line(environ, "HOME");
	else if (i == 2 && str[1] == '+')
		tmp = ms_get_line(environ, "PWD");
	else if (i == 2 && str[1] == '-')
		tmp = ms_get_line(environ, "OLDPWD");
	str += i;
	str = ft_strjoin(tmp, str);
	return (str);
}
