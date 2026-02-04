*This project has been created as part of the 42 curriculum by mimeyer*

# Description

This project aims to receive the next line from the user specified file descriptor. It should handle false fd's, return each line seperately ending with either \n or \0 and clean up after itself.
Furthermore it should work with any Buffer size supplied without issues.

# Instructions

Compilation
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

Execution
valgrind --leak-check=full --log-file=grind.log ./a.out
./a.out

# Resources

AI was used to ask about errors and memory leaks occuring, AI did not write this project it only taught concepts

# Algorithm

a static variable acting as the buffer is initialized with BUFFER_SIZE, it is then read into by read(), the status of read() is crosschecked with the expected output. depending on this, the buffer is grown to the next appropriate size to be read into again until the buffer contains either \n or \0. In this case, the result is cropped out, so that the buffer only contains the remaining content without the returned value. At EOF the function checks if the Buffer is NULL, frees it and returns NULL, finishing job without leaving leaks or corruption.
