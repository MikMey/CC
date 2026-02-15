/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_dealer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:31:40 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/15 18:36:33 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief distribute tasks to functions
 *
 * @param argc
 * @param argv
 * @return head
 */
t_int_cdll	*input_dealer(int argc, char *argv)
{
	char		**arr_input;
	t_int_cdll	*lst_nums;
	int			i;

	arr_input = ft_split(unify_input(argc, argv), ' ');
	lst_nums = NULL;
	i = 0;
	while (arr_input[i])
		ADD_NODE(&lst_nums, NEW_NODE(ft_atoi(arr_input[i++])));
	free_arr(arr_input);
	if (!(check_input(&lst_nums)))
	{
		LST_FREE(&lst_nums);
		throw_error(INPUT_VALUE_ERROR);
	}
	return (lst_nums);
}
