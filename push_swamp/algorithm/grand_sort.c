/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:08:35 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/03 22:24:16 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	grand_push(t_int_cdll **stck, t_ops **ops, t_ops_arr *ops_arr,
		t_ll **lis)
{
	t_ll	*lis_node;
	int		len_a;
	int		len_b;
	int		len_lis;

	len_lis = ll_len(*lis);
	len_b = 0;
	len_a = LST_LEN(stck[A]);
	lis_node = *lis;
	while (has_elem_or_buff(stck[A], *lis))
	{
		if (stck[A]->idx == lis_node->buff
			&& stck[A]->nxt->idx == lis_node->idx)
		{
			add_apply(stck, ops, "sa", ops_arr[SA]);
			lladd_after(&lis_node, llnew(lis_node->buff));
			lis_node->buff = -1;
		}
		else if (stck[A]->idx > lis_node->idx && (stck[A]->idx < (*lis)->idx
				|| (lis_node->nxt && stck[A]->idx < lis_node->nxt->idx))
			&& lis_node->buff == -1)
		{
			lis_node->buff = stck[A]->idx;
			len_lis++;
		}
		else if (stck[A]->idx == lis_node->idx)
		{
			add_apply(stck, ops, "ra", ops_arr[RA]);
			if (lis_node->nxt == NULL)
				lis_node = *lis;
			else
				lis_node = lis_node->nxt;
		}
		else
		{
			if (stck[A]->idx <= ((len_a / DIV) + ADD + len_b + len_lis)
				* PUSH_MULT && stck[A]->idx != lis_node->buff)
			{
				add_apply(stck, ops, "pb", ops_arr[PB]);
				if (stck[B]->idx < len_b * ROT_MULT)
					add_apply(stck, ops, "rb", ops_arr[RB]);
				len_b++;
			}
			else
				add_apply(stck, ops, "ra", ops_arr[RA]);
		}
	}
}

bool	has_elem_or_buff(t_int_cdll *stck, t_ll *lis)
{
	int	len;

	len = LST_LEN(stck);
	while (len > 0)
	{
		if (lis && (stck->idx == lis->idx || lis->buff != -1))
		{
			stck = stck->nxt;
			if (lis->buff != -1)
				return (1);
			lis = lis->nxt;
		}
		else
			return (1);
		len--;
	}
	return (0);
}
