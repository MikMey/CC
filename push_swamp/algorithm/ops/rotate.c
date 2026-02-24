/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:22 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/24 20:07:03 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_int_cdll **head_a, t_int_cdll **head_b)
{
	*head_a = (*head_a)->nxt;
}

void	rb(t_int_cdll **head_a, t_int_cdll **head_b)
{
	*head_b = (*head_b)->nxt;
}

void	rr(t_int_cdll **head_a, t_int_cdll **head_b)
{
	ra(head_a, head_b);
	rb(head_a, head_b);
}
