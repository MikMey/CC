#!/bin/bash

GREEN='\033[1;32m'
RED='\033[1;31m'
NC='\033[0m'
BOLDNC='\033[1m'

compile () {
	gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=$1 main.c ../get_next_line.c ../get_next_line_utils.c
}

grind () {
	valgrind --leak-check=full --log-file=$1 ./a.out $2
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
	printf "\012\012\011${BOLDNC}[START\011GNL_TEST]${NC}\011\012\012\012"
}

success () {
	printf "$1 ${GREEN}[OK]${NC}\012"
}

fail () {
	printf "$1 ${RED}[KO]${NC}\012"
}

run_test () {
	testcase=("Empty" "Fd" "Smaller" "Bigger" "Same" "Continue" "Multiple")
	buffersize=(1 1 100 1 10 10 10)
	for i in $(seq 0 5);
	do
		compile ${buffersize[$i]}
		./a.out $i
		if [ $? -eq 1 ] 
			then
			success ${testcase[$i]}
		else
			fail ${testcase[$i]}
		fi
	done
}

start_test
check_norm
run_test
