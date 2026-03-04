/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dealer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:46:26 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/04 18:37:01 by mimeyer          ###   ########.fr       */
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
void	algo_dealer(t_int_cdll **head_a, t_ps *ps)
{
	size_t		len;
	t_int_cdll	*head_b;

	ps->ops_arr = init_ops_arr();
	head_b = NULL;
	ps->stck = malloc(sizeof(t_int_cdll *) * 3);
	ps->stck[A] = *head_a;
	ps->stck[B] = head_b;
	ps->stck[2] = NULL;
	len = LST_LEN(*head_a);
	opsnew_add(&(ps->ops), "", (int)len, 0);
	if (len <= 3)
		sort_three(ps);
	else if (len <= 5)
		sort_five(ps);
	else
		sort_grand(ps);
	free(ps->ops_arr);
	free_int_cdll(&(ps->stck[A]));
	free_int_cdll(&(ps->stck[B]));
	free(ps->stck);
	return ;
}

/**
 * @brief sort three parameters, hard coded
 *
 * @param head_a
 * @param head_b
 * @param ops
 */
void	sort_three(t_ps *ps)
{
	if ((ps->stck[A])->data < (ps->stck[A])->nxt->data
		&& (ps->stck[A])->nxt->data > (ps->stck[A])->prev->data
		&& (ps->stck[A])->prev->data > (ps->stck[A])->data)
	{
		add_apply(ps, RRA);
		add_apply(ps, SA);
	}
	else if ((ps->stck[A])->data > (ps->stck[A])->nxt->data
		&& (ps->stck[A])->nxt->data > (ps->stck[A])->prev->data)
	{
		add_apply(ps, SA);
		add_apply(ps, RRA);
	}
	else if ((ps->stck[A])->data < (ps->stck[A])->nxt->data
		&& (ps->stck[A])->nxt->data > (ps->stck[A])->prev->data
		&& (ps->stck[A])->prev->data < (ps->stck[A])->data)
		add_apply(ps, RRA);
	else if ((ps->stck[A])->data > (ps->stck[A])->nxt->data
		&& (ps->stck[A])->nxt->data < (ps->stck[A])->prev->data
		&& (ps->stck[A])->prev->data < (ps->stck[A])->data)
		add_apply(ps, RA);
	else if ((ps->stck[A])->data > (ps->stck[A])->nxt->data
		&& (ps->stck[A])->nxt->data < (ps->stck[A])->prev->data
		&& (ps->stck[A])->prev->data > (ps->stck[A])->data)
		add_apply(ps, SA);
}

/**
 * @brief sort five parameters using three sort and push/pull from b
 *
 * @param head_a
 * @param head_b
 * @param ops
 */
void	sort_five(t_ps *ps)
{
	int	len;

	len = LST_LEN(ps->stck[A]);
	if (check_sorted(ps->stck[A]))
		return ;
	if (len == 5)
		add_apply(ps, PB);
	add_apply(ps, PB);
	if (ps->stck[B]->nxt && (ps->stck[B])->data > (ps->stck[B])->nxt->data)
		add_apply(ps, SB);
	sort_three(ps);
	while (ps->stck[B])
	{
		if (((ps->stck[A])->prev->idx < (ps->stck[B])->idx
				&& ((ps->stck[A])->idx == 0
					|| (ps->stck[A])->idx > ps->stck[B]->idx))
			|| ps->stck[B]->idx == 0)
			add_apply(ps, PA);
		else
			add_apply(ps, RA);
	}
	while (ps->stck[A]->idx != 0)
		add_apply(ps, RA);
}

void	sort_grand(t_ps *ps)
{
	int	high_idx;
	int	last;

	ps->lis = fill_lis(ps->stck[A]);
	grand_push(ps);
	last = (ll_last(ps->lis))->idx;
	while (ps->stck[A]->idx != last)
		add_apply(ps, RA);
	free_ll(&(ps->lis));
	high_idx = get_high_idx(ps->stck[B]);
	insert_k(ps, high_idx);
	while (ps->stck[A]->idx != 0)
		add_apply(ps, RA);
}

int	get_high_idx(t_int_cdll *stck)
{
	int	len;
	int	high;

	high = stck->idx;
	len = LST_LEN(stck);
	while (len > 0)
	{
		if (stck->idx > high)
			high = stck->idx;
		stck = stck->nxt;
		len--;
	}
	return (high);
}
