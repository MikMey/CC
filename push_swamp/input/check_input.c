/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:30:48 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/19 19:13:05 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



bool	check_input(t_int_cdll **head)
{
	t_int_cdll	*node;
	int			*arr;
	size_t		len;
	size_t		i;

	i = 0;
	len = LST_LEN(*head);
	arr = ft_calloc(sizeof(int), len + 1);
	node = *head;
	while (len > 0)
	{
		while (arr[i] != 0)
		{
			if (arr[i] == node->data)
				return (free(arr), 0);
			i++;
		}
		arr[i] = node->data;
		node = node->nxt;
		len--;
	}
	return(1);
}
