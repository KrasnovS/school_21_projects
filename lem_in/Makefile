# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 22:16:37 by lfarlen           #+#    #+#              #
#    Updated: 2019/09/21 15:52:03 by lfarlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
OPTI			= -I

LS				= ls -1
GREP			= grep
MKDIR			= mkdir -p
RM				= rm -rf

SRC_PATH		= sources
LIB_PATH		= libft
INC_PATH		= include
INC_LIB_PATH	= include \
							$(LIB_PATH)/include
DOBJ			= objets

SRC_FILES		:= $(shell $(LS) $(SRC_PATH) | $(GREP) .c$)
OBJ_FILES		:= $(SRC_FILES:.c=.o)
LIBFT			:= libft.a

SRC_FILES		:= $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ_FILES		:= $(addprefix $(DOBJ)/, $(OBJ_FILES))
FINCLIB			:= $(addprefix $(OPTI) , $(INC_LIB_PATH))
LIBFT			:= $(addprefix $(LIB_PATH)/, $(LIBFT))

all: libft $(OBJ_FILES) $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(OBJ_FILES) $(LIBFT) -lncurses -o $@

$(DOBJ)/%.o: $(SRC_PATH)/%.c $(INC_PATH)
	@$(MKDIR) $(DOBJ)
	$(CC) $(CFLAGS) -c $< $(FINCLIB) -o $@

libft:
	make -C $(LIB_PATH)

clean:
	make -C $(LIB_PATH) clean
	$(RM) $(DOBJ)

fclean: clean
	make -C $(LIB_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
