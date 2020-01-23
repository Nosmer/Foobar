/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:48:40 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/23 18:37:26 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		get_tilde(char *args, char **environ)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (args[1] == '/')
		ft_strcpy(tmp, "HOME=");
	else if (args[1] == '+')
		ft_strcpy(tmp, "PWD=");
	else if (args[1] == '-')
		ft_strcpy(tmp, "OLDPWD=");
	else
	{
		while (args[i] != '/')
		{
			ft_strcat(tmp, &args[i]);
			i++;
		}
	}
printf("%s\n", tmp);
	while (*environ)
	{
		tmp = ft_strnstr(*environ, tmp, ft_strlen(tmp));
		environ++;
	}
}

void		args_check(char **args, char **environ)
{
	while (*args)
	{
		ft_putchar(*args[0]);
		if (*args[0] == '~')
			get_tilde(*args, environ);
//		if (*args[0] == '$')
//			get_param(*args, environ);
		args++;
	}
}
