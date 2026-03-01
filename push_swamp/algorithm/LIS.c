/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:35:22 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/01 21:14:19 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ll	*fill_lis(t_int_cdll *stck)
{
	int 		len;
	t_lis_ll	*temp;
	t_lis_ll	*save;
	t_lis_ll	*lis;

	lis = NULL;
	len = LST_LEN(stck) + 1;
	while(--len > 0)
	{
		lisadd_back(&lis, new_lis(get_lis(stck, len)));
		stck = stck->nxt;
	}
	len = get_high_len(lis);
	while (lis)
	{
		if (lis->len == len)
		{
			save = lis;
			lis = lis->nxt;
			continue;
		}
		temp = lis->nxt;
		free_ll(&(lis->head));
		free(lis);
		lis = temp;
	}
	return(save->head);
}

void free_ll(t_ll **head)
{
	t_ll *temp;
	
	while(*head)
	{
		temp = (*head)->nxt;
		free(*head);
		*head = temp;
	}
}

void	lisadd_back(t_lis_ll **head, t_lis_ll *node)
{
	t_lis_ll *last;

	if (!(*head))
	{
		(*head) = node;
		return;
	}
	last = lis_last(*head);
	last->nxt = node;
	return;
}

t_lis_ll	*lis_last(t_lis_ll *head)
{
	while(head->nxt)
		head = head->nxt;
	return(head);
}

t_lis_ll	*new_lis(t_ll	*content)
{
	t_lis_ll	*node;

	node = malloc(sizeof(t_lis_ll));
	if (node == NULL)
		return(NULL);
	node->head = content;
	node->len = llsize(content);
	node->nxt = NULL;
	return (node);
}

int llsize(t_ll *head)
{
	int len;

	len = 0;
	while(head)
	{
		head = head->nxt;
		len ++;
	}
	return(len);
}

t_ll	*get_lis(t_int_cdll *stck, int len)
{
	int	count;
	int end;
	t_ll	*head;
	int prev_idx;

	prev_idx = stck->idx;
	head = NULL;
	count = 1;
	end = len - 1;
	lladd_back(&head, llnew(stck->idx));
	stck = stck->nxt;
	while (end > 0)
	{
		if (stck->idx > prev_idx && stck->idx <= ((len / DIV) + ADD + count))
		{
			lladd_back(&head, llnew(stck->idx));
			count ++;
			prev_idx = stck->idx;
		}
		stck = stck->nxt;
		end--;
	}
	return(head);
}

t_ll *llnew(int idx)
{
	t_ll *node;

	node = malloc(sizeof(t_ll));
	if (!node)
		return(NULL);
	node ->idx = idx;
	node->nxt = NULL;
	return(node);
}

t_ll *ll_last(t_ll *head)
{
	while ( head->nxt)
		head = head->nxt;
	return(head);
}

void lladd_back(t_ll **head, t_ll *node)
{
	t_ll * last;

	if(!(*head))
	{
		*head = node;
		return;
	}
	last = ll_last(*head);
	last->nxt = node;
}

int	get_high_len(t_lis_ll *lis)
{
	int len;

	len = 0;
	while(lis)
	{
		if (lis->len > len)
			len = lis->len;
		lis = lis->nxt;
	}
	return(len);
}
