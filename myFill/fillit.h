/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:43:16 by bconsuel          #+#    #+#             */
/*   Updated: 2019/06/18 13:47:59 by bconsuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# define B_MAP_POS board->map[tet->x + i][tet->y + j]
# define T_MAP_POS tet->map[i][j]

/*
** Throwaway struct to store coordinates of a first # of
** a tetrimino. Is used in ft_store get_coords function.
*/
typedef struct		s_coord
{
	int				top;
	int				bottom;
	int				left;
	int				right;
}					t_coord;

/*
**  Linked list element, stores a map of a tetrimino, its
** allocated letter, general size and x/y position of the
** first element of a tetrimino on our board.
*/
typedef struct		s_tet
{
	char			**map;
	char			letter;
	int				x;
	int				y;
	int				width;
	int				height;
	struct s_tet	*next;
}					t_tet;

/*
** Main data structure. Stores a pointer at the beginning
** of the t_tet linked list, a number of t_tet elements,
** and a map where we are going to place our tetriminos
** with its size;
*/
typedef struct		s_board
{
	t_tet			*tets;
	int				nb_tet;
	int				size;
	char			**map;
}					t_board;

int					ft_init(t_board *board, char *file);
int					ft_validate(t_board *board, const char *file);
void				ft_puterr(int c);
void				ft_store(t_board *board, char *buf);
void				ft_solve(t_board *board);

#endif
