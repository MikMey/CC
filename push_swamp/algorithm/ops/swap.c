/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/01 16:15:51 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// void	s_any(t_int_cdll **head)
// {
// 	int temp;

// 	temp = (*head)->data;
// 	(*head)->data = (*head)->nxt->data;
// 	(*head)->nxt->data = temp;
// }

void	sa(t_int_cdll **stck)
{
	t_int_cdll	*temp;

	temp = stck[A];
	stck[A] = stck[A]->nxt;
	if (stck[A]->nxt == temp)
		return;
	temp->nxt = stck[A]->nxt;
	stck[A]->prev = temp->prev;
	temp->prev = stck[A];
	stck[A]->nxt = temp;
	temp->nxt->prev = temp;
	stck[A]->prev->nxt = stck[A];
}

void	sb(t_int_cdll **stck)
{
	t_int_cdll	*temp;

	temp = stck[B];
	stck[B] = stck[B]->nxt;
	if (stck[B]->nxt == temp)
		return;
	temp->nxt = stck[B]->nxt;
	stck[B]->prev = temp->prev;
	temp->prev = stck[B];
	stck[B]->nxt = temp;
	temp->nxt->prev = temp;
	stck[B]->prev->nxt = stck[B];
}

void	ss(t_int_cdll **stck)
{
	sa(stck);
	sb(stck);
}
