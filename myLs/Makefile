# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 13:47:09 by bconsuel          #+#    #+#              #
#    Updated: 2019/11/05 14:13:46 by bconsuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re
NAME = ft_ls
SRC_L = ./libft
SRC_H = main.c init_list.c parse_args.c
FLAG = -Wall -Werror -Wextra

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
