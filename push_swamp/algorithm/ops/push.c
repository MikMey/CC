/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:17 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/18 21:15:39 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	p_any(t_int_cdll **head_from, t_int_cdll **head_to)
{
	t_int_cdll *tmp;
	tmp = (*head_from);
	if ((*head_from)->nxt = (*head_from))
		(*head_from) = NULL;
	else
	{
		(*head_from)->nxt->prev = (*head_from)->prev;
		(*head_from)->prev->nxt = (*head_from)->nxt;
	}
	addfront_int_cdll(head_to, tmp); 
}
