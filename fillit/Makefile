NAME = fillit

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c main.c \
	figurki.c \
	checker.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_memset.c \
	ft_strlen.c \
	map.c \
	mover.c \
	solver.c \
	validatior.c \
	-I.fillit.h

	gcc -Wall -Wextra -Werror main.o \
	figurki.o \
	checker.o \
	ft_memalloc.o \
	ft_memdel.o \
	ft_memset.o \
	ft_strlen.o \
	map.o \
	mover.o \
	solver.o \
	validatior.o \
	-I.fillit.h -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all clean

.PHONY: clean re fclean all
