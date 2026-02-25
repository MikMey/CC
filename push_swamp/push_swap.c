/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:32 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 18:08:10 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ops		*ops;
	t_int_cdll	*lst_nums; // root of list
	// t_int_cdll	*dupl_lst;
	lst_nums = input_dealer(argc, argv);
	// dupl_lst = COPY_LST(&lst_nums);
	ops = algo_dealer(&lst_nums);
	
	t_ops *node;
	node = ops;
	node = node->nxt;
	while (node)
	{
		printf("%s\n", node->op);
		node = node->nxt;
	}
	free_ops(&ops);
}
