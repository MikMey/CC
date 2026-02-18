/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dealer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:46:26 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/16 17:12:11 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**algo_dealer(t_int_cdll **head)
{
	size_t	len;

	len = LST_LEN(head);
	if (len <= 3)
		return (sort_three(head));
	else if (len <= 5)
		return (sort_five(head));
	else if (len <= 7)
		return (sort_seven(head));
	else
		return (sort_grand(head));
}

char	**sort_three(t_int_cdll **head)
{
	char	**ops;

	if ((*head)->data < (*head)->nxt->data < (*head)->prev->data)
		return (NULL);
	ops
}

char	**sort_five(t_int_cdll **head)
{
}

char	**sort_seven(t_int_cdll **head)
{
}

char	**sort_grand(t_int_cdll **head)
{
}
