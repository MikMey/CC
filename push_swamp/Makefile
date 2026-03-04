CC := cc -Wall -Werror -Wextra -g
NAME := push_swap
SRC := input_dealer.c \
push_swap.c \
algorithm/algo_dealer.c \
algorithm/grand_sort.c \
algorithm/k_insert.c \
algorithm/LIS.c \
algorithm/modify.c \
utils/algo_utils.c \
utils/cdll_utils_2.c \
utils/cdll_utils.c \
utils/errors.c \
utils/grand_utils.c \
utils/input_utils.c \
utils/lis_util.c \
utils/ll_util2.c \
utils/ll_util.c \
utils/ops_utils2.c \
utils/ops_utils.c \
algorithm/ops/push.c \
algorithm/ops/reverse_rotate.c \
algorithm/ops/rotate.c \
algorithm/ops/swap.c

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

test: 
	clear
	$(CC) *.c */*.c */*/*.c -o $(NAME)

format:
	PATH="$$HOME/.local/bin:$$PATH" find . -type f -name "*.[c-h]" ! -name "test.*" -exec c_formatter_42 {} \;	

.PHONY: all re clean fclean