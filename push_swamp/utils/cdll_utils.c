/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:32:15 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 19:25:30 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief add note to list
 *
 * @param head
 * @param node
 */
void	add_int_cdll(t_int_cdll **head, t_int_cdll *node)
{
	if (!(*head))
		*head = node;
	else
	{
		if (!((*head)->nxt))
			(*head)->nxt = node;
		if ((*head)->prev)
		{
			node->prev = (*head)->prev;
			(*head)->prev->nxt = node;
		}
		else
			node->prev = (*head);
		node->nxt = *head;
		(*head)->prev = node;
	}
}

/**
 * @brief create a new node
 *
 * @param data
 * @return node*
 */
t_int_cdll	*new_int_cdll_node(int data)
{
	t_int_cdll	*node;

	node = malloc(sizeof(t_int_cdll));
	if (!node)
		throw_error(MALLOC_ERROR);
	node->nxt = NULL;
	node->prev = NULL;
	node->data = data;
	node->idx = -1;
	return (node);
}

size_t	len_int_cdll(t_int_cdll *head)
{
	t_int_cdll	*node;
	size_t		len;

	if (!head)
		return (0);
	else if (head->nxt == NULL)
		return (1);
	len = 1;
	node = head->nxt;
	while (node != head)
	{
		node = node->nxt;
		len++;
	}
	return (len);
}

void	free_int_cdll(t_int_cdll **head)
{
	size_t		len;
	t_int_cdll	*temp;
	t_int_cdll	*node;

	if (!head)
		return ;
	len = LST_LEN(*head);
	node = *head;
	while (len > 0)
	{
		temp = node->nxt;
		free(node);
		node = temp;
		len--;
	}
	return;
}

t_int_cdll	*copy_int_cdll(t_int_cdll **head)
{
	t_int_cdll	*new_lst;
	size_t		len;
	t_int_cdll	*node;

	len = LST_LEN(*head);
	node = (*head);
	while (len > 0)
	{
		ADD_NODE(&new_lst, NEW_NODE(node->data));
		node = node->nxt;
		len--;
	}
	return (new_lst);
}
