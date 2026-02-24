/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/24 20:09:41 by mimeyer          ###   ########.fr       */
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

void	sa(t_int_cdll **head_a, t_int_cdll **head_b)
{
	int temp;

	temp = (*head_a)->data;
	(*head_a)->data = (*head_a)->nxt->data;
	(*head_a)->nxt->data = temp;
}

void	sb(t_int_cdll **head_a, t_int_cdll **head_b)
{
	int temp;

	temp = (*head_b)->data;
	(*head_b)->data = (*head_b)->nxt->data;
	(*head_b)->nxt->data = temp;
}

void	ss(t_int_cdll **head_a, t_int_cdll **head_b)
{
	s_any(head_a);
	s_any(head_b);
}
