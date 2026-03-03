/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dealer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:46:26 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/03 13:28:35 by mimeyer          ###   ########.fr       */
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
	return (free(stck), ops);
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
	}
	else if (IDX_ONE > IDX_TWO && IDX_TWO > IDX_LAST) // 3 2 1
	{
		add_apply(stck, ops, "sa", ops_arr[SA]);
		add_apply(stck, ops, "rra", ops_arr[RRA]);
	}
	else if (IDX_ONE < IDX_TWO && IDX_TWO > IDX_LAST && IDX_LAST < IDX_ONE)
		// 2 3 1
		add_apply(stck, ops, "rra", ops_arr[RRA]);
	else if (IDX_ONE > IDX_TWO && IDX_TWO < IDX_LAST && IDX_LAST < IDX_ONE)
		// 3 1 2
		add_apply(stck, ops, "ra", ops_arr[RA]);
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
	int	len;

	len = LST_LEN(stck[A]);
	if (check_sorted(stck[A]))
		return ;
	if (len == 5)
		add_apply(stck, ops, "pb", ops_arr[PB]);
	add_apply(stck, ops, "pb", ops_arr[PB]);
	if (stck[B]->nxt && (stck[B])->data > (stck[B])->nxt->data)
		add_apply(stck, ops, "sb", ops_arr[SB]);
	sort_three(stck, ops, ops_arr);
	while (stck[B])
	{
		if (((stck[A])->prev->idx < (stck[B])->idx && ((stck[A])->idx == 0
					|| (stck[A])->idx > stck[B]->idx)) || stck[B]->idx == 0)
			add_apply(stck, ops, "pa", ops_arr[PA]);
		else
			add_apply(stck, ops, "ra", ops_arr[RA]);
	}
	while (stck[A]->idx != 0)
		add_apply(stck, ops, "ra", ops_arr[RA]);
}

void	sort_grand(t_int_cdll **stck, t_ops **ops, t_ops_arr *ops_arr)
{
	t_ll	*lis;
	int		high_idx;
	int last;
	
	lis = fill_lis(stck[A]);
	grand_push(stck, ops, ops_arr, &lis);
	last = (ll_last(lis))->idx;
	while (stck[A]->idx != last)
		add_apply(stck, ops, "ra", ops_arr[RA]);
	free_ll(&lis);
	high_idx = get_high_idx(stck[B]);
	insert_k(stck, ops, ops_arr, high_idx);
	while (stck[A]->idx != 0)
		add_apply(stck, ops, "ra", ops_arr[RA]);
}

void	insert_k(t_int_cdll **stck, t_ops **ops, t_ops_arr *ops_arr, int high)
{
	int dir;
	
	dir = RIGHT;
	while (stck[B])
	{
		if (stck[A]->idx < high)
			add_apply(stck, ops, "ra", ops_arr[RA]);
		else if (stck[A]->idx != (high + 1))
		{
			while (stck[A]->idx != (high + 1))
				add_apply(stck, ops, "rra", ops_arr[RRA]);
		}
		dir = get_dir(stck[B], high);
		if (dir == RIGHT)
		{
			while(stck[B]->idx != high)
				add_apply(stck, ops, "rb", ops_arr[RB]);
		}
		else
		{
			while(stck[B]->idx != high)
				add_apply(stck, ops, "rrb", ops_arr[RRB]);
		}
		add_apply(stck, ops, "pa", ops_arr[PA]);
		if (stck[B])
			high = get_high_idx(stck[B]);
	}
}

int	get_dir(t_int_cdll *stck, int idx)
{
	int buff;
	int set;
	t_int_cdll *temp;

	set = LST_LEN(stck) / DIV + ADD;
	buff = set;
	temp = stck;
	while (true)
	{
		while (buff > 0)
		{
			if (temp->idx == idx)
				return (RIGHT);
			temp = temp->nxt;
			buff--;
		}
		buff = set;
		temp = stck;
		while (buff > 0)
		{
			if (temp->idx == idx)
				return (LEFT);
			temp = temp->prev;
			buff--;
		}
		set *= 2;
		buff = set;
		temp = stck;
	}
}

int	get_high_idx(t_int_cdll *stck)
{
	int len;
	int high;

	high = stck->idx;
	len = LST_LEN(stck);
	while(len > 0)
	{
		if (stck->idx > high)
			high = stck->idx;
		stck = stck->nxt;
		len --;
	}
	return(high);
}

void	grand_push(t_int_cdll **stck, t_ops **ops, t_ops_arr *ops_arr, t_ll **lis)
{
	t_ll *lis_node;
	int	len_a;
	int len_b;
	int len_lis;

	len_lis = 0;
	len_b = 0;
	len_a = LST_LEN(stck[A]);
	lis_node = *lis;
	while (has_elem_or_buff(stck[A], *lis))
	{
		if (stck[A]->idx == lis_node->buff && stck[A]->nxt->idx == lis_node->idx) //buff and lis next to each other
		{
			add_apply(stck, ops, "sa", ops_arr[SA]);
			lladd_after(&lis_node, llnew(lis_node->buff));
			lis_node->buff = -1;
		}
		else if (stck[A]->idx > lis_node->idx && (stck[A]->idx < (*lis)->idx || (lis_node->nxt && stck[A]->idx < lis_node->nxt->idx)) && lis_node->buff == -1) //can be added to lis buff
			lis_node->buff = stck[A]->idx;
		else if (stck[A]->idx == lis_node->idx) //is lis elem
		{
			add_apply(stck, ops, "ra", ops_arr[RA]);
			if (lis_node->nxt == NULL)
			{
				len_lis = 0;
				lis_node = *lis;
			}
			else
			{
				len_lis ++;
				lis_node = lis_node->nxt;
			}
		}
		else //any other
		{
			if (stck[A]->idx <= (len_a / DIV) + ADD + len_b + len_lis && stck[A]->idx != lis_node->buff)
			{	
				add_apply(stck, ops, "pb", ops_arr[PB]);
				if (stck[B]->idx < len_b * ROT_MULT)
					add_apply(stck, ops, "rb", ops_arr[RB]);
				len_b ++;
			}
			else
				add_apply(stck, ops, "ra", ops_arr[RA]);
		}
	}
}

bool	has_elem_or_buff(t_int_cdll *stck,t_ll *lis)
{
	int len;

	len = LST_LEN(stck);
	while (len > 0)
	{
		if (lis && (stck->idx == lis->idx || lis->buff != -1))
		{
			stck = stck->nxt;
			if (lis->buff != -1)
				return(1);
			lis = lis->nxt;
		}
		else
			return(1);
		len --;
	}
	return(0);
}
