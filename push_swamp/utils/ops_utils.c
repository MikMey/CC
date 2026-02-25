/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:25:00 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 15:48:46 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	opsnew_add(t_ops **head, char *op, int len_a, int len_b)
{
	t_ops	*last;

	last = ops_last(*head);
	if (len_a == -1)
		len_a = last->ln_a;
	if (len_b == -1)
		len_b = last->ln_b;
	ops_addback(head, ops_newnode(op, len_a, len_b));
}

void	ops_addback(t_ops **head, t_ops *node)
{
	t_ops	*last;

	if (!(*head))
	{
		(*head) = node;
		return ;
	}
	last = ops_last(*head);
	last->nxt = node;
}

t_ops	*ops_last(t_ops *head)
{
	while (head->nxt)
	{
		head = head->nxt;
	}
	return (head);
}

t_ops	*ops_newnode(char *op, int len_a, int len_b)
{
	t_ops	*node;

	node = malloc(sizeof(t_ops));
	if (!node)
		return (NULL);
	node->op = op;
	node->ln_a = len_a;
	node->ln_b = len_b;
	node->nxt = NULL;
	return (node);
}

t_ops_arr	*init_ops_arr(void)
{
	t_ops_arr	*ops_arr;

	ops_arr = malloc(sizeof(ops_arr) * 11);
	ops_arr[SA] = &sa;
	ops_arr[SB] = &sb;
	ops_arr[SS] = &ss;
	ops_arr[PA] = &pa;
	ops_arr[PB] = &pb;
	ops_arr[RA] = &ra;
	ops_arr[RB] = &rb;
	ops_arr[RR] = &rr;
	ops_arr[RRA] = &rra;
	ops_arr[RRB] = &rrb;
	ops_arr[RRR] = &rrr;
	ops_arr[11] = NULL;
	return (ops_arr);
}
