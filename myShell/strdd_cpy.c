/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdd_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:57:07 by bconsuel          #+#    #+#             */
/*   Updated: 2020/01/24 14:01:57 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Makes a copy of a 2d array src and returns a fresh 2d array.
*/

char	**strdd_cpy(char **src)
{
	char	**arr;
	int		i;
	int		len;
	int		wid;

	i = 0;
	len = 0;
	wid = 0;
	while (src[len])
		len++;
	if (!(arr = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		wid = ft_strlen(src[i] + 1);
		arr[i] = malloc(wid);
		ft_memcpy(arr[i], src[i], wid + 1);
		i++;
	}
	return (arr);
}

/*
** Main for testing
**int		main(int argc, char **argv, char **envp)
**{
**	char	**res;
**	int		i;
**
**	i = 0;
**	res = strdd_cpy(envp);
**	while (res[i])
**	{
**		if (!ft_strcmp(envp[i], res[i]))
**			printf("difference in row: %d\n", i);
**		i++;
**	}
**	return (0);
**}
*/
