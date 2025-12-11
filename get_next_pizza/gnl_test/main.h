#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include "../get_next_line.h"

#define FR_CUR {free(fd);free(res);return (0);}
#define FR_MULT_RET return(free(line),free(lines), 0);


#define EMPTY	"/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/empty.txt"

#define SMALLER	"/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/big1.txt", \
				"/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/big2.txt", \
				"/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/big3.txt" 

#define SMALL_LINES "This is a test for real\n", \
					"Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah Blah \n", \
					"Bruh we end here\0"

#define BIGGER	"/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/small1.txt", \
				"/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/small2.txt", \
				"/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/small3.txt" 

#define BIG_LINES	"L\n", \
					"\n", \
					"R\0"

#define SAME	"/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/same1.txt", \
				"/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/same2.txt"

#define SAME_LINES	"tes\n", \
					"eof\0"

#define CONTINUE "/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/continues.txt"
					 
#define CONT_LINES	"This\n", \
					"is\n", \
					"\n", \
					"a a a a a a a a a a a a a a a a a a \n", \
					"test    \n", \
					""


typedef int (*f_arr)(void);

int empty(void);
int fd(void);
int smaller(void);
int bigger(void);
int same(void);
int continues(void);
int multiple(void);

#define CAT 	"CAT\n",\
				"CAT CAT \n",\
				"CAT CAT CAT \n",\
				"CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"CAT CAT CAT CAT CAT CAT \n",\
				"\0"

#define DOG 	"DOG DOG DOG\n",\
				"DOG DOG DOG DOG\n",\
				"DOG DOG \n",\
				"DOG DOG DOG DOG\n",\
				"DOG DOG DOG DOG\n",\
				"DOG DOG DOG DOG\n",\
				"DOG DOG DOG DOG\n",\
				"DOG DOG DOG DOG DOG DOG DOG DOG DOG DOG DOG DOG\n",\
				"DOG DOG DOG DOG DOG DOG DOG DOG\n",\
				"DOG DOG DOG DOG DOG DOG DOG DOG DOG DOG DOG DOG\n",\
				"\0"

#define FISH	"FISH fish \n",\
				"FISH FISH FISH \n",\
				"FISH fish FISH FISH \0"
#define TEXT "This\n",\
			"is a\n",\
			"file I want to read\0"

#endif 