/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:01:20 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/03 22:06:52 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lisadd_back(t_lis_ll **head, t_lis_ll *node)
{
	t_lis_ll	*last;

	if (!(*head))
	{
		(*head) = node;
		return ;
	}
	last = lis_last(*head);
	last->nxt = node;
	return ;
}

t_lis_ll	*lis_last(t_lis_ll *head)
{
	while (head->nxt)
		head = head->nxt;
	return (head);
}

t_lis_ll	*new_lis(t_ll *content)
{
	t_lis_ll	*node;

	node = malloc(sizeof(t_lis_ll));
	if (node == NULL)
		return (NULL);
	node->head = content;
	node->len = llsize(content);
	node->nxt = NULL;
	return (node);
}
