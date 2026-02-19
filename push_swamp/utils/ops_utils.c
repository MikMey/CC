/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:25:00 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/19 18:57:27 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	opsnew_add(t_ops **head, char *op, int len_a, int len_b)
{
	ops_addback(head, ops_newnode(op, len_a, len_b));
}

void	ops_addback(t_ops **head, t_ops *node)
{
	if (!(*head))
	{
		(*head) = node;
		return;
	}
	while((*head)->nxt != NULL)
		*head = (*head)->nxt;
	(*head)->nxt = node;
}

t_ops	*ops_newnode(char *op, int len_a, int len_b)
{
	t_ops	*node;
	node = malloc(sizeof(t_ops));
	if (!node)
		return(NULL);
	node->op = op;
	node->ln_a = len_a;
	node->ln_b = len_b;
	node->nxt = NULL;
	return (node);
}
