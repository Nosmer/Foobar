# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 12:05:59 by bconsuel          #+#    #+#              #
#    Updated: 2019/08/30 15:13:57 by bconsuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re
NAME = libftprint.a
SRC = ft_printf.c ft_parse_format.c ft_handle_type.c ft_char.c \
	  ft_string.c ft_int.c ft_uint.c ft_pointer.c ft_int_oct.c \
	  ft_hexuint.c ft_double_f.c ft_double_lf.c ft_add_lst.c \
	  ft_prnt_lst.c ft_free_lst.c ft_prnt_arr.c ft_print.c \
	  ft_pow.c
SRC_O = $(SRC:.c=.o)
SRC_L = ./libft
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(SRC_L) re

clean:
	@make -C $(SRC_L) clean

fclean: clean
	@make -C $(SRC_L) fclean

re: fclean all
