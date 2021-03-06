/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:48:55 by bconsuel          #+#    #+#             */
/*   Updated: 2020/02/03 12:33:07 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char	line[50] = "FooBar${HOME}FooBar $PWD FooBar";
	char	**words;

	words = get_words(line);
	while (*words)
	{
		printf("%s\n", *words);
		words++;
	}
	return (0);
}
