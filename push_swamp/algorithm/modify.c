/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:02:44 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 15:49:41 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_apply(t_int_cdll **stck, t_ops **ops_head, char *ops, t_ops_arr fc)
{
	opsnew_add(ops_head, ops, -1, -1);
	fc(stck);
}
// pb,pa,sa,sb,ra,rb,rra,rrb,rrr
