/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dealer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:46:26 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 18:16:42 by mimeyer          ###   ########.fr       */
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
	t_int_cdll	**stck;
	t_ops_arr	*ops_arr;

	ops_arr = init_ops_arr();
	head_b = NULL;
	ops = NULL;
	stck = malloc(sizeof(t_int_cdll *) * 3);
	stck[A] = *head_a;
	stck[B] = head_b;
	stck[2] = NULL;
	len = LST_LEN(*head_a);
	opsnew_add(&ops, "", (int)len, 0);
	if (len <= 3)
		sort_three(stck, &ops, ops_arr);
	else if (len <= 5)
		sort_five(stck, &ops, ops_arr);
	else
		sort_grand(stck, &ops, ops_arr);
	free(ops_arr);
	free_int_cdll(&(stck[A]));
	free_int_cdll(&(stck[B]));
	free(stck);
	return(ops);
}

/**
 * @brief sort three parameters, hard coded
 *
 * @param head_a
 * @param head_b
 * @param ops
 */
void	sort_three(t_int_cdll **stck, t_ops **ops, t_ops_arr *ops_arr)
{
	if (IDX_ONE < IDX_TWO && IDX_TWO > IDX_LAST && IDX_LAST > IDX_ONE) // 1 3 2
	{
		add_apply(stck, ops, "rra", ops_arr[RRA]);
		add_apply(stck, ops, "sa", ops_arr[SA]);
		add_apply(stck, ops, "ra", ops_arr[RA]);
	}
	else if (IDX_ONE > IDX_TWO && IDX_TWO > IDX_LAST) // 3 2 1
	{
		add_apply(stck, ops, "sa", ops_arr[SA]);
		add_apply(stck, ops, "rra", ops_arr[RRA]);
	}
	else if (IDX_ONE < IDX_TWO && IDX_TWO > IDX_LAST && IDX_LAST < IDX_ONE)
		// 2 3 1
		add_apply(stck, ops, "ra", ops_arr[RA]);
	else if (IDX_ONE > IDX_TWO && IDX_TWO < IDX_LAST && IDX_LAST < IDX_ONE)
		// 3 1 2
		add_apply(stck, ops, "rra", ops_arr[RRA]);
	else if (IDX_ONE > IDX_TWO && IDX_TWO < IDX_LAST && IDX_LAST > IDX_ONE)
		// 2 1 3
		add_apply(stck, ops, "sa", ops_arr[SA]);
}

/**
 * @brief sort five parameters using three sort and push/pull from b
 *
 * @param head_a
 * @param head_b
 * @param ops
 */
void	sort_five(t_int_cdll **stck, t_ops **ops, t_ops_arr *ops_arr)
{
	if (check_sorted(stck[A]))
		return ;
	add_apply(stck, ops, "pb", ops_arr[PB]);
	add_apply(stck, ops, "pb", ops_arr[PB]);
	if ((stck[B])->data > (stck[B])->nxt->data)
		add_apply(stck, ops, "sb", ops_arr[SB]);
	sort_three(stck, ops, ops_arr);
	while (!check_sorted(stck[B]))
	{
		if ((stck[A])->data > (stck[B])->data)
			add_apply(stck, ops, "pa", ops_arr[PA]);
		else
			add_apply(stck, ops, "ra", ops_arr[RA]);
	}
}

void	sort_grand(t_int_cdll **stck, t_ops **ops, t_ops_arr *ops_arr)
{
	stck[A] = stck[B];
	(*ops)->op = "hi";
	(void)ops_arr;
}
