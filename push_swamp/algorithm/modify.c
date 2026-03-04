/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:02:44 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/04 18:35:38 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_apply(t_ps *ps, int idx)
{
	opsnew_add(&(ps->ops), ps->str_ops[idx], -1, -1);
	ps->ops_arr[idx](ps->stck);
}
// pb,pa,sa,sb,ra,rb,rra,rrb,rrr
