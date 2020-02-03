# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 12:33:18 by bconsuel          #+#    #+#              #
#    Updated: 2020/02/03 15:22:55 by bconsuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re
NAME = minishell
SRC_L = ./lib
SRC_H = main.c get_token.c shell_read.c shell_run.c shell_split.c \
		ft_reallocate.c strdd_cpy.c strdd_free.c strdd_print.c \
		ms_get_param.c ms_get_tilde.c ms_signals.c
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(SRC_L)
	@gcc -g $(FLAG) $(SRC_H) -I $(SRC_L) -L $(SRC_L) -lft -o $(NAME)

clean:
	@make -C $(SRC_L) clean

fclean: clean
	@make -C $(SRC_L) fclean
	@rm -f $(NAME)
	@rm -rf minishell.dSYM

re: fclean all
