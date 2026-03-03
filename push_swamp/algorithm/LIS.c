/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:35:22 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/03 22:06:41 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ll	*fill_lis(t_int_cdll *stck)
{
	int			len;
	t_lis_ll	*temp;
	t_ll		*save;
	t_lis_ll	*lis;

	lis = NULL;
	len = LST_LEN(stck) + 1;
	stck = get_all_lis(stck, lis, len);
	len = get_high_len(lis);
	while (lis)
	{
		if (lis->len == len)
		{
			save = lis->head;
			len = -1;
		}
		else
			free_ll(&(lis->head));
		temp = lis->nxt;
		free(lis);
		lis = temp;
	}
	return (save);
}

t_int_cdll	*get_all_lis(t_int_cdll *stck, t_lis_ll *lis, int len)
{
	while (--len > 0)
	{
		lisadd_back(&lis, new_lis(get_lis(stck, len)));
		stck = stck->nxt;
	}
	return (stck);
}

t_ll	*get_lis(t_int_cdll *stck, int len)
{
	int		count;
	int		end;
	t_ll	*head;
	int		prev_idx;

	prev_idx = stck->idx;
	head = NULL;
	count = 1;
	end = len - 1;
	lladd_back(&head, llnew(stck->idx));
	stck = stck->nxt;
	while (end > 0)
	{
		if (stck->idx > prev_idx && stck->idx <= ((len / DIV) + ADD + (count
					* LIS_MULT)))
		{
			lladd_back(&head, llnew(stck->idx));
			count++;
			prev_idx = stck->idx;
		}
		stck = stck->nxt;
		end--;
	}
	return (head);
}

int	get_high_len(t_lis_ll *lis)
{
	int	len;

	len = 0;
	while (lis)
	{
		if (lis->len > len)
			len = lis->len;
		lis = lis->nxt;
	}
	return (len);
}
