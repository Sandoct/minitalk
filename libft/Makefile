# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:01:39 by gpouzet           #+#    #+#              #
#    Updated: 2023/02/15 19:32:54 by gpouzet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
FLAGS = -Wall -Wextra -Werror 

NAME = libft.a

SRC 	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_isnumber.c \
			ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memchr.c ft_memcmp.c ft_memmove.c \
			ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c \
			ft_strnstr.c ft_calloc.c ft_strdup.c \
			ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_atoi.c ft_itoa.c ft_substr.c \
			ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c \
			lst/ft_lstnew.c lst/ft_lstadd_front.c lst/ft_lstsize.c \
			lst/ft_lstlast.c lst/ft_lstadd_back.c lst/ft_lstdelone.c \
			lst/ft_lstclear.c lst/ft_lstiter.c lst/ft_lstmap.c \
			printf/ft_printf.c\
			printf/ft_charsize.c printf/ft_digits.c printf/ft_hexa.c\
			printf/ft_toolsprintf.c\
			GNL/get_next_line.c\

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo -n "\033[2K"
	@echo -n "\\r\033[1;32m[compilation completed]"

%.o: %.c
	@echo -n "\\r\033[2K"
	@echo -n "\\r\033[1;33m[compiling...]"$<
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@echo "\033[1;32m[object files cleaned]"

fclean: clean
	@rm -rf $(NAME) 
	@echo "\033[1;32m[Library deleted]"

re: fclean all

.PHONY: all so list clean fclean re
