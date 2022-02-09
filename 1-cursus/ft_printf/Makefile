# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 07:19:46 by mdoquocb          #+#    #+#              #
#    Updated: 2022/01/29 10:07:20 by mdoquocb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CL = rm -rf

HEADER =	ft_printf.h \
		ft_printf_bonus.h \

SRC = 	ft_printf.c \
	ft_printf_utils.c \

SRCB =	ft_printf_bonus.c \
	ft_printf_flag_bonus.c \
	ft_printf_dispatch_flag_csp_bonus.c \
	ft_printf_dispatch_flag_duxo_bonus.c \
	ft_printf_put_c_bonus.c \
	ft_printf_put_s_bonus.c \
	ft_printf_put_p_bonus.c \
	ft_printf_put_du_bonus.c \
	ft_printf_put_x_bonus.c \
	ft_printf_flag_app_bonus.c \

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(CL) $(OBJ) $(OBJB)

fclean: clean
	$(CL) $(NAME)

re: fclean all

bonus: $(OBJB)
	@ar r $(NAME) $(OBJB)

.PHONY :all	clean	fclean	re
