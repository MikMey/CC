/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:29 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/13 12:58:26 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include "libft/libft.h"

typedef struct s_int_CDDL {
	int data;
	struct s_int_CDDL *nxt;
	struct s_int_CDDL *prev;
} t_int_CDLL;

# define BOLD_RED "\e[1;31m"
# define RESET_COLOR "\e[0m"
# define BOLD_WHITE "\e[1;37m"

# define MALLOC_ERROR "\nERROR\n\nMalloc failed to allocate; terminating\n"
# define INPUT_VALUE_ERROR "\nERROR\n\nInput arguments are bad; terminating\n"
# define INPUT_ERROR "\nERROR\n\nInput is bad; terminating\n"
# define NULL_POINTER "\nERROR\n\nNull pointer exception error; terminating\n"

int		main(int argc, char **argv);
char	*unify_input(int argc, char **argv);
void	throw_error(char *s);
t_int_CDLL *new_int_CDLL_node(int	data);
void add_int_CDDL(t_int_CDLL **head, int data);

#endif
