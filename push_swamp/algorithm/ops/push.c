/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:17 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/24 20:08:50 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// void	p_any(t_int_cdll **head_from, t_int_cdll **head_to)
// {
// 	t_int_cdll *tmp;
// 	tmp = (*head_from);
// 	if ((*head_from)->nxt == (*head_from))
// 		(*head_from) = NULL;
// 	else
// 	{
// 		(*head_from)->nxt->prev = (*head_from)->prev;
// 		(*head_from)->prev->nxt = (*head_from)->nxt;
// 	}
// 	addfront_int_cdll(head_to, tmp); 
// }

void	pa(t_int_cdll **head_a, t_int_cdll **head_b)
{
	t_int_cdll *tmp;
	tmp = (*head_b);
	if ((*head_b)->nxt == (*head_b))
		(*head_b) = NULL;
	else
	{
		(*head_b)->nxt->prev = (*head_b)->prev;
		(*head_b)->prev->nxt = (*head_b)->nxt;
	}
	addfront_int_cdll(head_a, tmp); 
}

void	pb(t_int_cdll **head_a, t_int_cdll **head_b)
{
	t_int_cdll *tmp;
	tmp = (*head_a);
	if ((*head_a)->nxt == (*head_a))
		(*head_a) = NULL;
	else
	{
		(*head_a)->nxt->prev = (*head_a)->prev;
		(*head_a)->prev->nxt = (*head_a)->nxt;
	}
	addfront_int_cdll(head_b, tmp); 
}
