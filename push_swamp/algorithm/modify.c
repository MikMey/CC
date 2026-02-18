/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:02:44 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/18 20:30:01 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_apply(t_int_cdll **int_head_a, t_int_cdll **int_head_b,
		t_list **lst_head, char *ops)
{
	lstnew_add(lst_head, ops);
	if (ops == "sa")
		s_any(int_head_a);
	else if (ops == "sb")
		s_any(int_head_b);
	else if (ops == "ss")
		ss(int_head_a, int_head_b);
	else if (ops == "pb")
		p_any(int_head_a, int_head_b);
	else if (ops == "pa")
		p_any(int_head_b, int_head_a);
	else if (ops == "ra")
		r_any(int_head_a);
	else if (ops == "rb")
		r_any(int_head_b);
	else if (ops == "rr")
		rr(int_head_a, int_head_b);
	else if (ops == "rra")
		rr_any(int_head_a);
	else if (ops == "rrb")
		rr_any(int_head_b);
	else
		rrr(int_head_a, int_head_b);
}
