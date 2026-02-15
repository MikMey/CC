/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:29 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/15 18:46:21 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include "libft/libft.h"

# define NEW_NODE new_int_cdll_node
# define ADD_NODE add_int_cdll
# define LST_LEN len_int_cdll
# define LST_FREE free_int_cdll


typedef struct s_int_cdll
{
	int					data;
	struct s_int_cdll	*nxt;
	struct s_int_cdll	*prev;
}						t_int_cdll;

# define BOLD_RED "\e[1;31m"
# define RESET_COLOR "\e[0m"
# define BOLD_WHITE "\e[1;37m"

# define MALLOC_ERROR "\nERROR\n\nMalloc failed to allocate; terminating\n"
# define INPUT_VALUE_ERROR "\nERROR\n\nInput arguments are bad; terminating\n"
# define INPUT_ERROR "\nERROR\n\nInput is bad; terminating\n"
# define NULL_POINTER "\nERROR\n\nNull pointer exception error; terminating\n"

// main
int						main(int argc, char **argv);
t_int_cdll				copy_int_cdll(t_int_cdll **head);

// input
t_int_cdll				*input_dealer(int argc, char *argv);
char					*unify_input(int argc, char **argv);
bool					check_input(t_int_cdll **head);

// algo

// improve

// utils
void					throw_error(char *s);
void					free_arr(char **arr);
t_int_cdll				*new_int_cdll_node(int data);
void					add_int_cdll(t_int_cdll **head, t_int_cdll *node);
size_t					len_int_cdll(t_int_cdll **head);
void					free_int_cdll(t_int_cdll **head);


#endif
