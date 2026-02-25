/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:23:24 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 18:20:50 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	addfront_int_cdll(t_int_cdll **head, t_int_cdll *node)
{
	if (!(*head))
	{
		*head = node;
		return;
	}	
	node->nxt = (*head);
	node->prev = (*head)->prev;
	*head = node;
}
