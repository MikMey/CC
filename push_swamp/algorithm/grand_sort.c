/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:08:35 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/04 19:29:04 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	grand_push(t_ps *ps)
{
	t_ll	*lis_node;
	int		*len;

	len = ft_calloc(sizeof(int), 4);
	len[LIS] = ll_len(ps->lis);
	len[B] = 0;
	len[A] = LST_LEN(ps->stck[A]);
	lis_node = ps->lis;
	while (has_elem_or_buff(ps->stck[A], ps->lis))
	{
		if (ps->stck[A]->idx == lis_node->buff
			&& ps->stck[A]->nxt->idx == lis_node->idx)
			swap_buff(ps, &lis_node);
		else if (check_ins_buff(ps, lis_node))
		{
			lis_node->buff = ps->stck[A]->idx;
			len[LIS]++;
		}
		else if (ps->stck[A]->idx == lis_node->idx)
			rot_lis(ps, &lis_node);
		else
			len = mod_b(ps, lis_node, len);
	}
	free(len);
}

int	*mod_b(t_ps *ps, t_ll *lis_node, int *len)
{
	if (check_push(len, ps->stck, lis_node))
		len = rot_push(len, ps);
	else
		add_apply(ps, RA);
	return (len);
}

void	rot_lis(t_ps *ps, t_ll **lis_node)
{
	add_apply(ps, RA);
	if ((*lis_node)->nxt == NULL)
		(*lis_node) = ps->lis;
	else
		(*lis_node) = (*lis_node)->nxt;
}

void	swap_buff(t_ps *ps, t_ll **lis_node)
{
	add_apply(ps, SA);
	lladd_after(lis_node, llnew((*lis_node)->buff));
	(*lis_node)->buff = -1;
}

int	*rot_push(int *len, t_ps *ps)
{
	add_apply(ps, PB);
	if (ps->stck[B]->idx < len[B] * ROT_MULT)
		add_apply(ps, RB);
	len[B]++;
	return (len);
}
