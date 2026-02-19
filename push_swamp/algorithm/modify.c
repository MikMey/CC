/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:02:44 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/19 19:01:03 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_apply(t_int_cdll **int_head_a, t_int_cdll **int_head_b,
		t_ops **lst_head, char *ops)
{
	opsnew_add(lst_head, ops, LST_LEN(*int_head_a), LST_LEN(*int_head_b));
	if (ft_strncmp(ops, "sa", 2) == 0)
		s_any(int_head_a);
	else if (ft_strncmp(ops, "sb", 2) == 0)
		s_any(int_head_b);
	else if (ft_strncmp(ops, "ss", 2) == 0)
		ss(int_head_a, int_head_b);
	else if (ft_strncmp(ops, "pb", 2) == 0)
		p_any(int_head_a, int_head_b);
	else if (ft_strncmp(ops, "pa", 2) == 0)
		p_any(int_head_b, int_head_a);
	else if (ft_strncmp(ops, "ra", 2) == 0)
		r_any(int_head_a);
	else if (ft_strncmp(ops, "rb", 2) == 0)
		r_any(int_head_b);
	else if (ft_strncmp(ops, "rr", 2) == 0)
		rr(int_head_a, int_head_b);
	else if (ft_strncmp(ops, "rra", 3) == 0)
		rr_any(int_head_a);
	else if (ft_strncmp(ops, "rrb", 3) == 0)
		rr_any(int_head_b);
	else
		rrr(int_head_a, int_head_b);
}
