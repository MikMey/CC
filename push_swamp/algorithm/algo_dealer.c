/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dealer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:46:26 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/18 17:45:25 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	**algo_dealer(t_int_cdll **head_a)
{
	size_t	len;
	t_list *ops;
	t_int_cdll *head_b;

	len = LST_LEN(head_a);
	if (len <= 3)
		return(sort_three(head_a, &head_b, &ops), ops);
	else if (len <= 5)
		return (sort_five(head_a, &head_b, &ops), ops);
	else
		return (sort_grand(head_a, &head_b, &ops), ops);
}

void	sort_three(t_int_cdll **head_a, t_int_cdll **head_b, t_list **ops)
{
	if (IDX_ONE < IDX_TWO > IDX_LAST && IDX_LAST > IDX_ONE)
	{
		add_apply(head_a, head_b, ops, "rra");
		add_apply(head_a, head_b, ops, "sa");
		add_apply(head_a, head_b, ops, "ra");
	}
	else if (IDX_ONE > IDX_TWO > IDX_LAST)
	{
		add_apply(head_a, head_b, ops, "ra");
		add_apply(head_a, head_b, ops, "ra");
	}
}

void	sort_five(t_int_cdll **head_a, t_int_cdll **head_b, t_list **ops)
{
}

void	sort_grand(t_int_cdll **head_a, t_int_cdll **head_b, t_list **ops)
{
}
