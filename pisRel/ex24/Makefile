# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 11:04:29 by bconsuel          #+#    #+#              #
#    Updated: 2019/04/04 11:09:14 by bconsuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRC_O = $(SRC:.c=.o)
BASE = srcs
INC = includes
VPATH = $(BASE) $(INC)

all: $(NAME)

$(NAME): $(SRC)
		gcc -c $^
		ar rc $@ $(SRC_O)

clean: $(SRC_O)
		rm -f $(SRC_O)

fclean: clean
		rm $(NAME)

re: fclean all
