*This project has been created as part of the 42 curriculum by mimeyer*

# Description

The goal of this project is to replicate the funtion of stdio printf with limitation to the flags "cspdiuxX%" and disregards buffer management.

The project consists of the receivng ft_printf function, which loops and delegates the flag management to flag_master, which calls operations based on the flag provided.

# Instructions

compilation can be done with the "make" command. further available commands are fclean, clean, all, re and format

# Resources

Main resources used was the va_args man page

# Algorithm and Data Structures

The main Algorithm is a while loop which checks for '%' and a if else statement to delegate special flag operations