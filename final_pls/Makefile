AR := ar rcs
CC := cc -Wall -Werror -Wextra
NAME := libftprintf.a
SRC := ./flag_master.c \
./ft_printf.c \
./write_print.c \
./flags/%_plus.c \
./flags/-_0_space.c \
./flags/d_i_u.c \
./flags/hash_dot.c \
./flags/p.c \
./flags/s_c.c \
./flags/x_X.c \

LIB_SRC := libft

OBJ := $(SRC:.c=.o)

%.o: %.c
	$(CC) -o $@ -c $<

$(NAME):	$(OBJ)
			make -C $(LIB_SRC)
			$(AR)	$@	$^

run: $(NAME)

all:	lib_make	run

clean:
		rm -rf $(OBJ) | make clean -C libft

fclean:	clean
		rm -rf $(NAME) | make fclean -C libft

re:	fclean all

test:
		clear && gcc -Wall -Werror -Wextra -g $(SRC) libft/*.c test.c

format:
	PATH="$$HOME/.local/bin:$$PATH" find . -type f -name "*.[c-h]" ! -name "test.*" -exec c_formatter_42 {} \;

.PHONY: all clean fclean re test
