AR := ar
AFLAGS := rcs
CC := cc -Wall -Werror -Wextra
NAME := libftprintf.a
SRC := ft_printf.c \
base.c

LIB_SRC := libft
LIB_A := $(LIB_SRC)/libft.a

OBJ := $(SRC:.c=.o)

%.o: %.c
	$(CC) -o $@ -c $<


$(NAME): $(LIB_A) $(OBJ)
	cp $(LIB_A) $(NAME)
	$(AR) $(AFLAGS) $(NAME) $(OBJ)

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

# test:
# 	$(CC) -g $(SRC) libft/*.c main.c

# val:
# 	valgrind --leak-check=full --log-file=grind.log ./a.out

# full: test val

# format:
# 	PATH="$$HOME/.local/bin:$$PATH" find . -type f -name "*.[c-h]" ! -name "test.*" -exec c_formatter_42 {} \;	

.PHONY: all re clean fclean