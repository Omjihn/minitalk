# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 16:27:11 by gbricot           #+#    #+#              #
#    Updated: 2023/04/25 13:26:53 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME):
	$(CC) server.c -o server
	$(CC) client.c -o client

all: $(NAME)

fclean:
	rm server client
