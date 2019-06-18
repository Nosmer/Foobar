# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 12:31:27 by bconsuel          #+#    #+#              #
#    Updated: 2019/06/18 13:02:27 by bconsuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re
NAME = fillit
SRC_L = ./libft
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C $(SRC_L) re
	@gcc $(FLAG) *.c -I $(SRC_L) -L $(SRC_L) -lft -o $(NAME)

clean:
	@make -C $(SRC_L) clean

fclean: clean
	@make -C $(SRC_L) fclean
	@rm -f $(NAME)

re: fclean all
