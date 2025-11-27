AR := ar
AFLAGS := rcs
CC := cc -Wall -Werror -Wextra
NAME := libftprintf.a
SRC := flag_master.c \
flags/%_plus.c \
flags/-_0_space.c \
flags/d_i_u.c \
flags/hash_dot.c \
flags/p.c \
flags/s_c.c \
flags/x_X.c \
flags/convert_base.c \
flags/flag_helper.c \
ft_printf.c

LIB_SRC := libft
LIB_A := $(LIB_SRC)/libft.a

OBJ := $(SRC:.c=.o)

%.o: %.c
	$(CC) -o $@ -c $<


$(NAME): $(LIB_A) $(OBJ)
	$(AR) $(AFLAGS) $(LIB_A) $(OBJ)
	cp ./libft/libft.a ./libftprintf.a

$(LIB_A):
	make -C $(LIB_SRC)

all:	$(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re:	fclean all

format:
	PATH="$$HOME/.local/bin:$$PATH" find . -type f -name "*.[c-h]" ! -name "test.*" -exec c_formatter_42 {} \;	

.PHONY: all re clean fclean format