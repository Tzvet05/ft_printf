# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttrave <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 18:16:33 by ttrave            #+#    #+#              #
#    Updated: 2023/11/29 18:16:37 by ttrave           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAG = -Wall -Wextra -Werror

HEADER = ./ft_printf.h

SRC = ft_printf.c \
	ft_convert.c \
	ft_convert2.c \
	ft_parse_params.c \
	ft_parse_params2.c \
	ft_print_format.c \
	ft_printf_utils.c

SRC_BONUS = ft_printf_bonus.c \
	ft_convert_bonus.c \
	ft_convert2_bonus.c \
	ft_parse_params_bonus.c \
	ft_parse_params2_bonus.c \
	ft_print_format_bonus.c \
	ft_printf_utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	mv libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJ) $(HEADER)

.c.o:
	$(CC) $(CFLAG) -I $(HEADER) -c $< -o $@

bonus: $(OBJ_BONUS)
	make -C libft/
	mv libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJ_BONUS) $(HEADER)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

clean:
	make clean -C libft/
	rm -f $(OBJ) $(OBJ_BONUS)

re:	fclean all

.PHONY: all fclean clean re bonus
