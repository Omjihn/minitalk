# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 16:27:11 by gbricot           #+#    #+#              #
#    Updated: 2023/05/01 18:15:28 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 	src/server.c \
	src/client.c \
	libft/ft_atoi.c \
	libft/ft_calloc.c \
	libft/ft_strdup.c \
	libft/ft_strlen.c

$(NAME):
	$(CC) server.c -o server
	$(CC) client.c -o client

all: $(NAME)

fclean:
	rm server client
