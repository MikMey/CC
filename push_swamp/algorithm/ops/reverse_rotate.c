/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:19 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/18 18:15:37 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rr_any(t_int_cdll **head)
{
	*head = (*head)->prev;
}

void	rrr(t_int_cdll **head_a, t_int_cdll **head_b)
{
	rr_any(head_a);
	rr_any(head_b);
}
