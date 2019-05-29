/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:43:16 by bconsuel          #+#    #+#             */
/*   Updated: 2019/05/29 11:24:16 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct		s_tet
{
	char			**map;
	char			letter;
	int				x;
	int				y;
	struct s_list	*next;
}					t_tet;

typedef struct		s_board
{
	t_tet			*tet;
	int				nb_tet;
	int				size;
	char			**map;
}					t_board;

int					ft_validate(t_board board, const char *file);
void				ft_puterr(int c);

#endif
