/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_make_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:12:38 by bconsuel          #+#    #+#             */
/*   Updated: 2020/02/03 16:06:02 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ms_path_ch(char *s1, char c)
{
	int		i;
	int		len;
	char	*res;

	i = -1;
	if (!s1 || !c)
		return (NULL);
	len = ft_strlen(s1);
	if (!(res = ft_strnew(len + 1)))
		return (NULL);
	while (++i < len)
		*(res + i) = *(s1 + i);
	*(res + 1) = c;
	return (res);
}

char		*ms_path_cl(char *s1, char *s2, int mode)
{
	char	*res;

	if (!(new = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	s1 = NULL;
	if (mode)
	{
		free(s2);
		s2 = NULL;
	}
	return (res);
}

char		*ms_make_path(char *s1, char *s2)
{
	int		len;
	char	*tmp;

	len = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	if (s1[len] != '/')
	{
		if (s2[0] == '/')
			return (ft_strjoin(s1, s2));
		else
		{
			tmp = ms_path_cl(ms_path_ch(p1, '/'), p2, 0);
			return (tmp);
		}
	}
	else
	{
		if (s2[0] == '/')
			return (ft_strjoin(s1, s2 + 1));
		else
			return (ft_strjoin(s1, s2));
	}
}
