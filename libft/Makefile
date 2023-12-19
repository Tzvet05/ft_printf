# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttrave <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 11:48:10 by ttrave            #+#    #+#              #
#    Updated: 2023/11/01 12:20:42 by ttrave           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAG = -Wall -Wextra -Werror

HEADER = ./libft.h

SRC =	ft_isdigit.c \
	ft_memset.c \
	ft_in.c \
	ft_strlen.c \
	ft_strncpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) $(HEADER)

.c.o:
	$(CC) $(CFLAG) -I $(HEADER) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re:	fclean all

.PHONY: all fclean clean re
