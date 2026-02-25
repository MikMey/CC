/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:19 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 15:29:46 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// void	rr_any(t_int_cdll **head)
// {
// 	*head = (*head)->prev;
// }

void	rra(t_int_cdll **stck)
{
	stck[A] = stck[A]->prev;
}

void	rrb(t_int_cdll **stck)
{
	stck[B] = stck[B]->prev;
}

void	rrr(t_int_cdll **stck)
{
	rra(stck);
	rrb(stck);
}
