/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:01:23 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/03 22:05:59 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ll_len(t_ll *head)
{
	int	len;

	len = 0;
	while (head)
	{
		head = head->nxt;
		len++;
	}
	return (len);
}

void	free_ll(t_ll **head)
{
	t_ll	*temp;

	while (*head)
	{
		temp = (*head)->nxt;
		free(*head);
		*head = temp;
	}
}

void	lladd_after(t_ll **head, t_ll *node)
{
	if (!(*head))
	{
		(*head) = node;
		return ;
	}
	node->nxt = (*head)->nxt;
	(*head)->nxt = node;
	return ;
}

int	llsize(t_ll *head)
{
	int	len;

	len = 0;
	while (head)
	{
		head = head->nxt;
		len++;
	}
	return (len);
}

t_ll	*llnew(int idx)
{
	t_ll	*node;

	node = malloc(sizeof(t_ll));
	if (!node)
		return (NULL);
	node->idx = idx;
	node->buff = -1;
	node->nxt = NULL;
	return (node);
}
