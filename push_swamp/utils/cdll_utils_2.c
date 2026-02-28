/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:23:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/28 21:49:32 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	addfront_int_cdll(t_int_cdll **head, t_int_cdll *node)
{
	if (!(*head))
	{
		*head = node;
		return ;
	}
	if ((*head)->nxt == NULL)
		node->prev = (*head);
	else
	{
		node->prev = (*head)->prev;
		(*head)->nxt->prev = node;
		(*head)->prev->nxt = node;
	}
	node->nxt = (*head);
	*head = node;
}
