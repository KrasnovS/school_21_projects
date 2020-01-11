# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prawney <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 13:44:07 by prawney           #+#    #+#              #
#    Updated: 2019/08/19 19:54:46 by prawney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_PATH = libft

SRC = 	ft_check_sort.c ft_sorting_one.c ft_sorting_two.c instructions_one.c instructions_two.c \
		validation.c ft_str_splitspaces.c \
		split_to_int.c ft_atoi_small.c what_operations.c

OBJ = $(SRC:.c=.o)

INC = 	push_swap.h \
		$(LIB_PATH)/includes/libft.h

FLAGS = -Wall -Wextra -Werror

all: checker push_swap

checker : checker.o $(OBJ) $(LIB_PATH)/libft.a
	gcc -o checker checker.o $(OBJ) $(FLAGS) -L $(LIB_PATH) -lft

push_swap : push_swap.o $(OBJ) $(LIB_PATH)/libft.a
	gcc -o push_swap push_swap.o $(OBJ) $(FLAGS) -L $(LIB_PATH) -lft

$(LIB_PATH)/libft.a: $(LIB_PATH)/Makefile $(LIB_PATH)/libft.h
	@make -C $(LIB_PATH)/ fclean && make -C $(LIB_PATH)
	@echo "libft created"

%.o: %.c $(INC)
	gcc -o $@ -c $< $(FLAGS) -I $(LIB_PATH)/

clean:
	make -C $(LIB_PATH)/ clean
	rm -f $(OBJ) checker.o push_swap.o

fclean: clean
	make -C $(LIB_PATH)/ fclean
	rm -f checker push_swap

re: fclean all
