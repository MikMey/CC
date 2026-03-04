/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:29 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/04 20:20:49 by mimeyer          ###   ########.fr       */
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

# define A 0
# define B 1
# define LIS 2

# define RIGHT 0
# define LEFT 1

# define DIV 20
# define ADD 7
# define LIS_MULT 20
# define ROT_MULT 1.06 // bigger: more bottom, smaller: more top
# define PUSH_MULT 1.02

# define BOLD_RED "\e[1;31m\0"
# define RESET_COLOR "\e[0m\0"
# define BOLD_WHITE "\e[1;37m\0"

# define MALLOC_ERROR "\nERROR\n\nMalloc failed to allocate; terminating\n\0"
# define INPUT_VALUE_ERROR "\nERROR\n\nInput arguments are bad; terminating\n\0"
# define INPUT_ERROR "\nERROR\n\nInput is bad; terminating\n\0"
# define NULL_POINTER "\nERROR\n\nNull pointer exception error; terminating\n\0"

typedef struct s_int_cdll
{
	int					data;
	int					idx;
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

typedef struct s_ll
{
	struct s_ll			*nxt;
	int					idx;
	int					buff;
}						t_ll;

typedef struct s_lis_ll
{
	int					len;
	struct s_ll			*head;
	struct s_lis_ll		*nxt;
}						t_lis_ll;

typedef void			(*t_ops_arr)(t_int_cdll **);

typedef struct s_ps
{
	t_int_cdll			**stck;
	t_ops				*ops;
	t_ops_arr			*ops_arr;
	t_ll				*lis;
	char				**str_ops;
}						t_ps;

// main
int						main(int argc, char **argv);
char					**init_str_ops(void);
char					**init_str_ops2(char **str_ops);
void					free_str_ops(char **str_ops);

// input
t_int_cdll				*input_dealer(int argc, char **argv);
char					*unify_input(int argc, char **argv);
void					check_input(char **arr, t_int_cdll **head);
bool					has_dup(t_int_cdll *head);
void					index_input(t_int_cdll *head);

// algo

// // dealer
void					algo_dealer(t_int_cdll **head_a, t_ps *ps);
void					sort_three(t_ps *ps);
void					sort_five(t_ps *ps);
void					sort_grand(t_ps *ps);
int						get_high_idx(t_int_cdll *stck);

// // modify
void					add_apply(t_ps *ps, int idx);

// // grand_sort
void					grand_push(t_ps *ps);
int						*mod_b(t_ps *ps, t_ll *lis_node, int *len);
void					rot_lis(t_ps *ps, t_ll **lis_node);
void					swap_buff(t_ps *ps, t_ll **lis_node);
int						*rot_push(int *len, t_ps *ps);

// // k_insert
void					insert_k(t_ps *ps, int high);
void					go_right(t_ps *ps, int high);
void					go_left(t_ps *ps, int high);
int						get_dir(t_int_cdll *stck, int idx);
int						check_dir(int set, int idx, t_int_cdll *stck,
							t_int_cdll *temp);

// // LIS
t_ll					*fill_lis(t_int_cdll *stck);
t_int_cdll				*get_all_lis(t_int_cdll *stck, t_lis_ll **lis, int len);
t_ll					*get_lis(t_int_cdll *stck, int len);
int						get_high_len(t_lis_ll *lis);

// // ops

// // // swap
void					sa(t_int_cdll **stck);
void					sb(t_int_cdll **stck);
void					ss(t_int_cdll **stck);

// // // push
void					pa(t_int_cdll **stck);
void					pb(t_int_cdll **stck);

// // // rotate
void					ra(t_int_cdll **stck);
void					rb(t_int_cdll **stck);
void					rr(t_int_cdll **stck);

// // // reverse_rotate
void					rra(t_int_cdll **stck);
void					rrb(t_int_cdll **stck);
void					rrr(t_int_cdll **stck);

// utils

// // algo_utils
bool					check_sorted(t_int_cdll *head);

// // errors
void					throw_error(char *s);
void					throw_arr(char *s, char **arr);
void					throw_arr_cdll(char *s, char **arr, t_int_cdll **head);
void					free_arr(char **arr);

// // cdll_utils
void					add_int_cdll(t_int_cdll **head, t_int_cdll *node);
t_int_cdll				*new_int_cdll_node(int data);
size_t					len_int_cdll(t_int_cdll *head);
void					free_int_cdll(t_int_cdll **head);
t_int_cdll				*copy_int_cdll(t_int_cdll **head);
void					addfront_int_cdll(t_int_cdll **head, t_int_cdll *node);

// // ops_utils
void					opsnew_add(t_ops **head, char *op, int len_a,
							int len_b);
void					ops_addback(t_ops **head, t_ops *node);
t_ops					*ops_last(t_ops *head);
t_ops					*ops_newnode(char *op, int len_a, int len_b);
t_ops_arr				*init_ops_arr(void);
void					free_ops(t_ops **ops);

// // input_utils
void					mtrx_isdigit(char **arr);
bool					check_i(t_int_cdll *head, int i);

// // lis_util
void					lisadd_back(t_lis_ll **head, t_lis_ll *node);
t_lis_ll				*lis_last(t_lis_ll *head);
t_lis_ll				*new_lis(t_ll *content);

// // ll_util
int						ll_len(t_ll *head);
void					free_ll(t_ll **head);
void					lladd_after(t_ll **head, t_ll *node);
int						llsize(t_ll *head);
t_ll					*llnew(int idx);
t_ll					*ll_last(t_ll *head);
void					lladd_back(t_ll **head, t_ll *node);

// // grand_utils
bool					check_ins_buff(t_ps *ps, t_ll *lis_node);
bool					check_push(int *len, t_int_cdll **stck, t_ll *lis_node);
bool					has_elem_or_buff(t_int_cdll *stck, t_ll *lis);

#endif
