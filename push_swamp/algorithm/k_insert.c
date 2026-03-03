/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_insert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:08:31 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/03 22:20:04 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_k(t_int_cdll **stck, t_ops **ops, t_ops_arr *ops_arr, int high)
{
	int	dir;

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
			go_right(stck, ops, high, ops_arr);
		else
			go_left(stck, ops, high, ops_arr);
		add_apply(stck, ops, "pa", ops_arr[PA]);
		if (stck[A]->nxt->idx == high - 1)
			add_apply(stck, ops, "sa", ops_arr[SA]);
		if (stck[B])
			high = get_high_idx(stck[B]);
	}
}

void	go_right(t_int_cdll **stck, t_ops **ops, int high, t_ops_arr *ops_arr)
{
	while (stck[B]->idx != high)
	{
		if (stck[B]->idx == high - 1)
			add_apply(stck, ops, "pa", ops_arr[PA]);
		else
			add_apply(stck, ops, "rb", ops_arr[RB]);
	}
}

void	go_left(t_int_cdll **stck, t_ops **ops, int high, t_ops_arr **ops_arr)
{
	while (stck[B]->idx != high)
	{
		if (stck[B]->idx == high - 1)
			add_apply(stck, ops, "pa", ops_arr[PA]);
		else
			add_apply(stck, ops, "rrb", ops_arr[RRB]);
	}
}

int	get_dir(t_int_cdll *stck, int idx)
{
	int			set;
	t_int_cdll	*temp;

	set = LST_LEN(stck) / DIV + ADD;
	temp = stck;
	return (check_dir(set, idx, stck, temp));
}

int	check_dir(int set, int idx, t_int_cdll *stck, t_int_cdll *temp)
{
	int	buff;

	buff = set;
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
