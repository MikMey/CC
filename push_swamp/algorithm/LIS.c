/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:35:22 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/01 19:54:47 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*fill_lis(t_int_cdll **stck)
{
	int 		len;
	t_lis_ll	*temp;
	t_lis_ll	*save;
	t_lis_ll	*lis;

	len = LST_LEN(stck[A]) + 1;
	while(--len > 0)
		lisadd_back(&lis, new_lis(get_lis(stck[A], len)));
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
		ft_lstclear(lis->head, NULL);
		free(lis);
		lis = temp;
	}
	return(save->head);
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
	while(head)
		head = head->nxt;
	return(head);
}

t_lis_ll	*new_lis(t_list	*content)
{
	t_lis_ll	*node;

	node = malloc(sizeof(t_lis_ll));
	if (node == NULL)
		return(NULL);
	node->head = content;
	node->len = ft_lstsize(content);
	node->nxt = NULL;
	return (node);
}

t_list	*get_lis(t_int_cdll **stck, int len)
{
	int	count;
	int end;
	t_list	*head;

	count = 1;
	end = len - 1;
	ft_lstadd_back(&head, ft_lstnew(stck[A]->idx));
	stck[A] = stck[A]->nxt;
	while (end > 0)
	{
		if (stck[A]->idx <= ((len / DIV) + ADD + count))
		{
			ft_lstadd_back(&head, ft_lstnew(stck[A]->idx));
			count ++;
		}
		stck[A] = stck[A]->nxt;
		end--;
	}
	return(head);
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
