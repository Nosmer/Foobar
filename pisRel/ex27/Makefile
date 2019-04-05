# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconsuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 13:07:15 by bconsuel          #+#    #+#              #
#    Updated: 2019/04/04 13:22:56 by bconsuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_display_file
SRC = ft_putchar.c ft_putstr.c main.c
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		gcc -c $^
		gcc -o $@ $(OBJECTS)

clean: $(OBJECTS)
		rm -f $(OBJECTS)

fclean: clean
		rm $(NAME)
