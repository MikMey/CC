/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:17 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 19:56:38 by mimeyer          ###   ########.fr       */
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

void	pa(t_int_cdll **stck)
{
	t_int_cdll	*tmp;

	tmp = stck[B];
	if (stck[B]->nxt == NULL)
		stck[B] = NULL;
	else
	{
		stck[B]->nxt->prev = stck[B]->prev;
		stck[B]->prev->nxt = stck[B]->nxt;
	}
	addfront_int_cdll((&stck[A]), tmp);
}

void	pb(t_int_cdll **stck)
{
	t_int_cdll	*tmp;

	tmp = stck[A];
	if (stck[A]->nxt == NULL)
		stck[A] = NULL;
	else
	{
		stck[A]->nxt->prev = stck[A]->prev;
		stck[A]->prev->nxt = stck[A]->nxt;
		stck[A] = stck[A]->nxt;
	}
	tmp->nxt = NULL;
	tmp->prev = NULL;
	addfront_int_cdll((&stck[B]), tmp);
}
