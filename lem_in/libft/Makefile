# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 14:50:07 by lfarlen           #+#    #+#              #
#    Updated: 2019/09/21 15:52:07 by lfarlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
AR		=	ar -rcs
CC		=	gcc

ifeq ($(DEBUG), yes)
FDEBUG	=	-Wextra -Wall -Werror
endif

WFLAGS	=	-Wall -Wextra -Werror -g
OPTI	=	-I
LS		=	ls -1
GREP	=	grep
MKDIR	=	mkdir -p
RM		=	rm -rf

DSRC	=	sources
DOBJ	=	objets
DINC	=	include

FSRC	:=	$(shell $(LS) $(DSRC) | $(GREP) \.c$)
FOBJ	:=	$(FSRC:.c=.o)

FSRC	:=	$(addprefix $(DSRC)/, $(FSRC))
FOBJ	:=	$(addprefix $(DOBJ)/, $(FOBJ))
FINC	:=	$(addprefix $(OPTI) , $(DINC))

all: $(FOBJ) $(NAME)

$(NAME): $(FOBJ)
	$(AR) $@ $(FOBJ)

$(DOBJ)/%.o: $(DSRC)/%.c $(DINC)
	$(MKDIR) $(DOBJ)
	$(CC) $(FDEBUG) $(WFLAGS) -c $< $(FINC) -o $@

clean:
	$(RM) $(DOBJ)

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all begin clean fclean r
