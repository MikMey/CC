CC := cc -Wall -Werror -Wextra -g
NAME := swap.a
SRC := push_swap.c \
algorithm/ops/push.c \
algorithm/ops/reverse_rotate.c \
algorithm/ops/rotate.c \
algorithm/ops/swap.c \
algorithm/algo_dealer.c \
algorithm/modify.c \
input/check_input \
input/input_dealer.c \
input/unify_input.c \
utils/algo_utils.c \
utils/cdll_utils.c \
utils/cdll_utils_2.c \
utils/errors.c \
utils/ops_utils.c

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
	valgrind --leak-check=full --log-file=grind.log ./$(NAME) $(ARGS)

test: 
	clear
	$(CC) *.c */*.c */*/*.c -o $(NAME)

full: re val

format:
	PATH="$$HOME/.local/bin:$$PATH" find . -type f -name "*.[c-h]" ! -name "test.*" -exec c_formatter_42 {} \;	

.PHONY: all re clean fclean