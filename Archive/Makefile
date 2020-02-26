# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 17:01:45 by cbouleng          #+#    #+#              #
#    Updated: 2019/12/29 18:38:10 by cbouleng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -I. -c

SRC = ft_printf_utils.c \
	ft_printf_utils2.c \
	ft_printf_utils3.c  \
	ft_prct_conv.c \
	ft_x_conv.c \
	ft_x_conv_2.c \
	ft_x_conv_3.c \
	ft_ix_conv.c \
	ft_ix_conv_2.c \
	ft_ix_conv_3.c \
	ft_s_conv.c \
	ft_s_conv_2.c \
	ft_s_conv_3.c \
	ft_s_conv_4.c \
	ft_c_conv.c \
	ft_c_conv_2.c \
	ft_p_conv.c \
	ft_p_conv_2.c \
	ft_di_conv.c \
	ft_di_conv_2.c \
	ft_di_conv_3.c \
	ft_di_conv_4.c \
	ft_u_conv.c \
	ft_u_conv_2.c \
	ft_u_conv_3.c \
	ft_printf.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
