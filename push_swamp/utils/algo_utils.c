/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:15:16 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/28 21:11:03 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	check_sorted(t_int_cdll *head)
{
	size_t	len;

	len = LST_LEN(head);
	while (len > 1)
	{
		if (head->data > head->nxt->data)
			return (0);
		head = head->nxt;
		len--;
	}
	return (1);
}
