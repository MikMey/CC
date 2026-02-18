/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:22 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/18 18:15:03 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	r_any(t_int_cdll **head)
{
	*head = (*head)->nxt;
}

void	rr(t_int_cdll **head_a, t_int_cdll **head_b)
{
	r_any(head_a);
	r_any(head_b);
}
