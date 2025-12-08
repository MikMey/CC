#!/bin/bash

GREEN='\033[1;32m'
RED='\033[1;31m'
NC='\033[0m'

compile () {
	gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=$1 main.c ../get_next_line.c ../get_next_line_utils.c
}

grind () {
	valgrind --leak-check=full --log-file=$1 ./a.out
}

check_norm () {
	norminette ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h > norm.txt
	if echo "Error" | grep -q 'Error' norm.txt
		then
		printf "Norminette ${RED}[KO]${NC}\012"
		cat norm.txt
			else
		printf "Norminette ${GREEN}[OK]${NC}\012"
	fi
}

start_test () {
	printf "[START GNL_TEST]"
}

start_test
check_norm
compile $42
grind grind.log
