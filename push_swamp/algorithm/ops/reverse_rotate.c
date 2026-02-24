/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:19 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/24 20:09:00 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// void	rr_any(t_int_cdll **head)
// {
// 	*head = (*head)->prev;
// }

void	rra(t_int_cdll **head_a, t_int_cdll **head_b)
{
	*head_a = (*head_a)->prev;
}

void	rrb(t_int_cdll **head_a, t_int_cdll **head_b)
{
	*head_b = (*head_b)->prev;
}

void	rrr(t_int_cdll **head_a, t_int_cdll **head_b)
{
	rra(head_a, head_b);
	rrb(head_a, head_b);
}
