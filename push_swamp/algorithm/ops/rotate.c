/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:54:22 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 15:32:41 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_int_cdll **stck)
{
	stck[A] = stck[A]->nxt;
}

void	rb(t_int_cdll **stck)
{
	stck[B] = stck[B]->nxt;
}

void	rr(t_int_cdll **stck)
{
	ra(stck);
	rb(stck);
}
