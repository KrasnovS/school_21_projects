NAME = libftprintf.a

HEAD = ft_printf.h
SRC = ft_printf.c lib_printf.c add_fnctns.c set_format.c apply_flags.c \
formats_c_s.c format_float.c formats_int.c pft_itoa.c pft_unsigned_itoa.c \
pft_float_itoa.c pft_float_itoa_2.c pft_float_itoa_3.c double_rep.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIB = -L libft -lft
LIBPATH = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBPATH)
	ar rcs $(NAME) $(OBJ) libft/*.o

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

clean:
	@make -C $(LIBPATH) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	@make -C $(LIBPATH) fclean
	/bin/rm -f $(NAME)

re: fclean all
