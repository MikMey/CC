/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_insert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:08:31 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/04 18:35:20 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_k(t_ps *ps, int high)
{
	int	dir;

	dir = RIGHT;
	while (ps->stck[B])
	{
		if (ps->stck[A]->idx < high)
			add_apply(ps, RA);
		else if (ps->stck[A]->idx != (high + 1))
		{
			while (ps->stck[A]->idx != (high + 1))
				add_apply(ps, RRA);
		}
		dir = get_dir(ps->stck[B], high);
		if (dir == RIGHT)
			go_right(ps, high);
		else
			go_left(ps, high);
		add_apply(ps, PA);
		if (ps->stck[A]->nxt->idx == high - 1)
			add_apply(ps, SA);
		if (ps->stck[B])
			high = get_high_idx(ps->stck[B]);
	}
}

void	go_right(t_ps *ps, int high)
{
	while (ps->stck[B]->idx != high)
	{
		if (ps->stck[B]->idx == high - 1)
			add_apply(ps, PA);
		else
			add_apply(ps, RB);
	}
}

void	go_left(t_ps *ps, int high)
{
	while (ps->stck[B]->idx != high)
	{
		if (ps->stck[B]->idx == high - 1)
			add_apply(ps, PA);
		else
			add_apply(ps, RRB);
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
