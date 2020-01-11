# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prawney <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 12:42:26 by prawney           #+#    #+#              #
#    Updated: 2019/08/17 14:54:13 by prawney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD = ft_printf.h
SRC = ft_printf.c lib_printf.c add_fnctns.c set_format.c apply_flags.c \
formats_c_s.c format_float.c formats_int.c pft_itoa.c pft_unsigned_itoa.c \
pft_float_itoa.c pft_float_itoa_2.c pft_float_itoa_3.c double_rep.c \
ft_sprintf.c ft_fdprintf.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIBPATH = ../

all: $(OBJ)

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

clean:
	/bin/rm -rf $(OBJ)
