/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:53:16 by bconsuel          #+#    #+#             */
/*   Updated: 2019/12/24 14:41:15 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr,size_t curr_size, size_t new_size)
{
	int		i;
	void	*ret;

	i = 0;
	if (newsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (malloc(size));
	else if (curr_size >= new_size)
		return ptr;
	else 
	{
		ret = malloc(new_size);
		if (ret)
		{
			ft_memcpy(ret, ptr, curr_size);
			free(ptr);
		}
		return ret;
	}
}
