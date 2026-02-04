CC := cc -Wall -Werror -Wextra -g
NAME := swap.a
SRC := push_swap.c

LIB_SRC := libft
LIB_A := $(LIB_SRC)/libft.a

$(NAME): $(LIB_A)
	$(CC) $(SRC) $(LIB_A) -o $(NAME)
	

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

val:
	valgrind --leak-check=full --log-file=grind.log ./$(NAME)

test: all val

full: re val

format:
	PATH="$$HOME/.local/bin:$$PATH" find . -type f -name "*.[c-h]" ! -name "test.*" -exec c_formatter_42 {} \;	

.PHONY: all re clean fclean