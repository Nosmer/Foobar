# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 12:33:18 by bconsuel          #+#    #+#              #
#    Updated: 2020/01/14 13:02:13 by bconsuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re
NAME = minishell
SRC_L = ./lib
SRC_H = main.c get_token.c shell_read.c shell_run.c shell_split.c
#FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(SRC_L)
	@gcc $(FLAG) $(SRC_H) -I $(SRC_L) -L $(SRC_L) -lft -o $(NAME)

clean:
	@make -C $(SRC_L) clean

fclean: clean
	@make -C $(SRC_L) fclean
	@rm -f $(NAME)

re: fclean all
