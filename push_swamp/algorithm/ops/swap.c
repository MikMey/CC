/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 15:49:16 by mimeyer          ###   ########.fr       */
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
	int	temp;

	temp = stck[A]->data;
	stck[A]->data = stck[A]->nxt->data;
	stck[A]->nxt->data = temp;
}

void	sb(t_int_cdll **stck)
{
	int	temp;

	temp = stck[B]->data;
	stck[B]->data = stck[B]->nxt->data;
	stck[B]->nxt->data = temp;
}

void	ss(t_int_cdll **stck)
{
	sa(stck);
	sb(stck);
}
