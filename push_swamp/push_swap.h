/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:29 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/24 19:56:42 by mimeyer          ###   ########.fr       */
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

// [&sa, &sb, &ss, &pa, &pb, &ra, &rb, &rr, &rra, &rrb, &rrr]

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# define IDX_ONE (*head_a)->data
# define IDX_TWO (*head_a)->nxt->data
# define IDX_LAST (*head_a)->prev->data

typedef void(*ops_arr)(t_int_cdll **, t_int_cdll**);

typedef struct s_int_cdll
{
	int					data;
	int 				idx;
	struct s_int_cdll	*nxt;
	struct s_int_cdll	*prev;
}						t_int_cdll;

typedef struct s_ops
{
	char				*op;
	int					ln_a;
	int					ln_b;
	struct s_ops		*nxt;
}						t_ops;

# define BOLD_RED "\e[1;31m"
# define RESET_COLOR "\e[0m"
# define BOLD_WHITE "\e[1;37m"

# define MALLOC_ERROR "\nERROR\n\nMalloc failed to allocate; terminating\n"
# define INPUT_VALUE_ERROR "\nERROR\n\nInput arguments are bad; terminating\n"
# define INPUT_ERROR "\nERROR\n\nInput is bad; terminating\n"
# define NULL_POINTER "\nERROR\n\nNull pointer exception error; terminating\n"

// main
int						main(int argc, char **argv);

// input
t_int_cdll				*input_dealer(int argc, char **argv);
char					*unify_input(int argc, char **argv);
bool					check_input(t_int_cdll **head);

// algo
t_ops					*algo_dealer(t_int_cdll **head);
void					sort_three(t_int_cdll **head_a, t_int_cdll **head_b,
							t_ops **ops);
void					sort_five(t_int_cdll **head_a, t_int_cdll **head_b,
							t_ops **ops);
void					sort_grand(t_int_cdll **head_a, t_int_cdll **head_b,
							t_ops **ops);
void					add_apply(t_int_cdll **int_head_a,
							t_int_cdll **int_head_b, t_ops **lst_head,
							char *ops);

// // ops
void					s_any(t_int_cdll **head);
void					ss(t_int_cdll **head_a, t_int_cdll **head_b);
void					p_any(t_int_cdll **head_from, t_int_cdll **head_to);
void					r_any(t_int_cdll **head);
void					rr(t_int_cdll **head_a, t_int_cdll **head_b);
void					rr_any(t_int_cdll **head);
void					rrr(t_int_cdll **head_a, t_int_cdll **head_b);

// improve

// utils
bool					check_sorted(t_int_cdll *head);
void					throw_error(char *s);
void					free_arr(char **arr);
t_int_cdll				*new_int_cdll_node(int data);
void					add_int_cdll(t_int_cdll **head, t_int_cdll *node);
size_t					len_int_cdll(t_int_cdll *head);
void					free_int_cdll(t_int_cdll **head);
t_int_cdll				*copy_int_cdll(t_int_cdll **head);
void					addfront_int_cdll(t_int_cdll **head, t_int_cdll *node);
void					opsnew_add(t_ops **head, char *op, int len_a, int len_b);
void					ops_addback(t_ops **head, t_ops *node);
t_ops					*ops_newnode(char *op, int len_a, int len_b);
t_ops	*ops_last(t_ops *head);
void	mtrx_isdigit(char **arr);

#endif
