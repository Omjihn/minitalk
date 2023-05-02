# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 11:06:21 by gbricot           #+#    #+#              #
#    Updated: 2023/05/02 11:24:29 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_C =	sources/client.c \
	libft/ft_calloc.c \
	libft/ft_atoi.c \
	libft/ft_strlen.c 

SRC_S = sources/server.c \
        libft/ft_calloc.c \
        libft/ft_atoi.c \
        libft/ft_strlen.c

OBJ_C = $(SRC_C:.c=.o)

OBJ_S = $(SRC_S:.c=.o)

PRINTF = Printf/libftprintf.a

$(NAME): $(OBJ_S) $(OBJ_C)
	@cd Printf && make
	$(CC) $(OBJ_C) $(PRINTF) -o $(NAME)
	$(CC) $(OBJ_S) $(PRINTF) -o server

all: $(NAME)

clean:
	rm -f $(OBJ_S) $(OBJ_C)

fclean: clean
	rm $(NAME)
	rm server
	@cd Printf && make fclean

re: fclean all
