# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 17:34:34 by gpouzet           #+#    #+#              #
#    Updated: 2023/02/21 13:52:01 by gpouzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

FLAGS = -Wall -Wextra -Werror

NAME = Minitalk

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)
	
$(NAME):
	@make --no-print-directory -C libft
	@$(CC) $(FLAGS) client.c -L./libft -lft -o client
	@$(CC) $(FLAGS) server.c -L./libft -lft -o server

bonus:
	@make --no-print-directory -C libft
	@$(CC) $(FLAGS) bonus/client_bonus.c -L./libft -lft -o client
	@$(CC) $(FLAGS) bonus/server_bonus.c -L./libft -lft -o server

clean:
	@make fclean --no-print-directory -C libft
	@echo "\033[1;32m[object files cleaned]"
	@rm -rf server.o client.o bonus/server.o

fclean: clean
	@rm -rf ./server ./client
	@echo "\033[1;32m[Programe deleted]"

re: fclean all

.PHONY: all clean fclean re
