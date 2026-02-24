/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dealer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:46:26 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/24 19:49:23 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


/**
 * @brief start algorithms for 3, 5 or big sort
 * 
 * 
 * @param head_a head of stack a
 * @return t_ops* list of operations 
 */
t_ops	*algo_dealer(t_int_cdll **head_a)
{
	size_t		len;
	t_ops		*ops;
	t_int_cdll	*head_b;
	ops_arr		*ops_arr;
	
	ops_arr = init_ops_arr();
	head_b = NULL;
	ops = NULL;
	len = LST_LEN(*head_a);
	opsnew_add(&ops, "", (int) len, 0);
	if (len <= 3)
		return (sort_three(head_a, &head_b, &ops), ops, ops_arr);
	else if (len <= 5)
		return (sort_five(head_a, &head_b, &ops), ops, ops_arr);
	else
		return (sort_grand(head_a, &head_b, &ops), ops, ops_arr);
}

/**
 * @brief sort three parameters, hard coded
 * 
 * @param head_a 
 * @param head_b 
 * @param ops 
 */
void	sort_three(t_int_cdll **head_a, t_int_cdll **head_b, t_ops **ops)
{
	if (IDX_ONE < IDX_TWO && IDX_TWO > IDX_LAST && IDX_LAST > IDX_ONE) // 1 3 2
	{
		add_apply(head_a, head_b, ops, "rra");
		add_apply(head_a, head_b, ops, "sa");
		add_apply(head_a, head_b, ops, "ra");
	}
	else if (IDX_ONE > IDX_TWO && IDX_TWO > IDX_LAST) // 3 2 1
	{
		add_apply(head_a, head_b, ops, "ra");
		add_apply(head_a, head_b, ops, "ra");
	}
	else if (IDX_ONE < IDX_TWO && IDX_TWO > IDX_LAST && IDX_LAST < IDX_ONE) // 2 3 1
		add_apply(head_a, head_b, ops, "ra");
	else if (IDX_ONE > IDX_TWO && IDX_TWO < IDX_LAST && IDX_LAST < IDX_ONE) // 3 1 2
		add_apply(head_a, head_b, ops, "rra");
	else if (IDX_ONE > IDX_TWO && IDX_TWO < IDX_LAST && IDX_LAST > IDX_ONE) // 2 1 3
		add_apply(head_a, head_b, ops, "sa");
}

/**
 * @brief sort five parameters using three sort and push/pull from b
 * 
 * @param head_a 
 * @param head_b 
 * @param ops 
 */
void	sort_five(t_int_cdll **head_a, t_int_cdll **head_b, t_ops **ops)
{
	if (check_sorted(*head_a))
		return;
	add_apply(head_a, head_b, ops, "pb");
	add_apply(head_a, head_b, ops, "pb");
	if ((*head_b)->data > (*head_b)->nxt->data)
		add_apply(head_a, head_b, ops, "sb");
	sort_three(head_a, head_b, ops);
	while(!check_sorted(*head_b))
	{
		if((*head_a)->data > (*head_b)->data)
			add_apply(head_a, head_b, ops, "pa");
		else
			add_apply(head_a, head_b, ops, "ra");
	}
	
}

void	sort_grand(t_int_cdll **head_a, t_int_cdll **head_b, t_ops **ops)
{
	head_a = head_b;
	(*ops)->op = "hi";
}
