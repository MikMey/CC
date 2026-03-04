/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:32 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/04 20:07:20 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ops		*node;
	t_int_cdll	*lst_nums;
	t_ps		*ps;

	lst_nums = input_dealer(argc, argv);
	ps = malloc(sizeof(t_ps));
	ps->ops = NULL;
	ps->str_ops = init_str_ops();
	algo_dealer(&lst_nums, ps);
	node = ps->ops;
	node = node->nxt;
	while (node)
	{
		ft_printf("%s\n", node->op);
		node = node->nxt;
	}
	free_ops(&(ps->ops));
	free_str_ops(ps->str_ops);
	free(ps);
}

char	**init_str_ops(void)
{
	char	**str_ops;

	str_ops = malloc(sizeof(char *) * 12);
	str_ops[SA] = ft_calloc(sizeof(char), 3);
	ft_strlcpy(str_ops[SA], "sa", 3);
	str_ops[SB] = ft_calloc(sizeof(char), 3);
	ft_strlcpy(str_ops[SB], "sb", 3);
	str_ops[SS] = ft_calloc(sizeof(char), 3);
	ft_strlcpy(str_ops[SS], "ss", 3);
	str_ops[PA] = ft_calloc(sizeof(char), 3);
	str_ops = init_str_ops2(str_ops);
	return (str_ops);
}

char	**init_str_ops2(char **str_ops)
{
	ft_strlcpy(str_ops[PA], "pa", 3);
	str_ops[PB] = ft_calloc(sizeof(char), 3);
	ft_strlcpy(str_ops[PB], "pb", 3);
	str_ops[RA] = ft_calloc(sizeof(char), 3);
	ft_strlcpy(str_ops[RA], "ra", 3);
	str_ops[RB] = ft_calloc(sizeof(char), 3);
	ft_strlcpy(str_ops[RB], "rb", 3);
	str_ops[RR] = ft_calloc(sizeof(char), 3);
	ft_strlcpy(str_ops[RR], "rr", 3);
	str_ops[RRA] = ft_calloc(sizeof(char), 4);
	ft_strlcpy(str_ops[RRA], "rra", 4);
	str_ops[RRB] = ft_calloc(sizeof(char), 4);
	ft_strlcpy(str_ops[RRB], "rrb", 4);
	str_ops[RRR] = ft_calloc(sizeof(char), 4);
	ft_strlcpy(str_ops[RRR], "rrr", 4);
	str_ops[11] = NULL;
	return (str_ops);
}

void	free_str_ops(char **str_ops)
{
	int	i;

	i = 0;
	while (str_ops[i])
	{
		free(str_ops[i]);
		i++;
	}
	free(str_ops);
}
