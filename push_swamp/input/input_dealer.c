/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_dealer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:31:40 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/23 21:19:48 by mimeyer          ###   ########.fr       */
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
t_int_cdll	*input_dealer(int argc, char **argv)
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

/**
 * @brief unify input from multiple arguments to one; also check for empty inputs
 *
 * @param argc
 * @param argv
 * @return unified input as single string
 */
char	*unify_input(int argc, char **argv)
{
	int		i;
	char	*input;

	i = 0;
	input = NULL;
	input = ft_calloc(sizeof(char), ft_strlen(argv[1]) + 1);
	if (argc <= 0)
		throw_error(INPUT_ERROR);
	else if (argc > 2)
	{
		while (argc > ++i)
		{
			if (!argv[i] || !*(argv[i]))
				throw_error(INPUT_VALUE_ERROR);
			input = ft_strjoin_free(&input, argv[i], " ");
			if (input == NULL)
				throw_error(MALLOC_ERROR);
		}
	}
	else if (!argv[1] || !*(argv[1]))
		throw_error(INPUT_VALUE_ERROR);
	else
		ft_strlcpy(input, argv[1], ft_strlen(argv[1]) + 1);
	return (input);
}

void	check_input(char **arr, t_int_cdll **head)
{
	int i;
	long long buff;
	mtrx_isdigit(arr);
	while (ft_strlen(arr[i]) < 11)
	{
		buff = ft_atoll(arr[i]);
		if (buff > INT_MAX || buff < INT_MIN)
			throw_arr_cdll(INPUT_VALUE_ERROR, arr, head);
		check_int_cdll(buff);
		ADD_NODE(head, NEW_NODE(buff));
		i++;
	}
	if(check_sorted(*head))
		throw_arr_cdll(INPUT_VALUE_ERROR, arr, head);
}

// 	t_int_cdll	*node;
// 	int			*arr;
// 	size_t		len;
// 	size_t		i;

// 	i = 0;
// 	len = LST_LEN(*head);
// 	arr = ft_calloc(sizeof(int), len + 1);
// 	node = *head;
// 	while (len > 0)
// 	{
// 		while (arr[i] != 0)
// 		{
// 			if (arr[i] == node->data)
// 				return (free(arr), 0);
// 			i++;
// 		}
// 		arr[i] = node->data;
// 		node = node->nxt;
// 		len--;
// 	}
// 	return(1);