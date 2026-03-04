/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:49:51 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/04 18:50:40 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	check_ins_buff(t_ps *ps, t_ll *lis_node)
{
	if (ps->stck[A]->idx > lis_node->idx && (ps->stck[A]->idx < ps->lis->idx
			|| (lis_node->nxt && ps->stck[A]->idx < lis_node->nxt->idx))
		&& lis_node->buff == -1)
		return (1);
	return (0);
}

bool	check_push(int *len, t_int_cdll **stck, t_ll *lis_node)
{
	if (stck[A]->idx <= ((len[A] / DIV) + ADD + len[B] + len[LIS]) * PUSH_MULT
		&& stck[A]->idx != lis_node->buff)
		return (1);
	return (0);
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
