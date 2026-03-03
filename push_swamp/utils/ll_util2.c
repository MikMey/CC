/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:06:19 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/03 22:06:38 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ll	*ll_last(t_ll *head)
{
	while (head->nxt)
		head = head->nxt;
	return (head);
}

void	lladd_back(t_ll **head, t_ll *node)
{
	t_ll	*last;

	if (!(*head))
	{
		*head = node;
		return ;
	}
	last = ll_last(*head);
	last->nxt = node;
}
