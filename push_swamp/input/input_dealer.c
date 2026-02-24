/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_dealer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:31:40 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/24 17:22:31 by mimeyer          ###   ########.fr       */
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
	t_int_cdll	*stack_a;
	int			i;

	stack_a = NULL;
	arr_input = ft_split(unify_input(argc, argv), ' ');
	check_input(arr_input, &stack_a);
	index_input(stack_a);
	return (stack_a);
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
	
	if(has_dup(*head) || check_sorted(*head))
		throw_arr_cdll(INPUT_VALUE_ERROR, arr, head);
	free_arr(arr);
	return;
}

/**
 * @brief check stack for duplicates
 * 
 * @details
 * for every node in stack_a,
 * go through entire stack,
 * find possible duplicate,
 * if found return,
 * else check next node
 * 
 * @param head 
 * @return true if duplicate detected
 * @return false if exits normally
 */
bool	has_dup(t_int_cdll *head)
{
	int	i;
	int j;
	int len;
	int	buff;

	i = 0;
	j = 0;
	buff = head->data;
	head = head->nxt;
	len = LST_LEN;
	while (i < len)
	{
		while (j < len)
		{
			if(head->data == buff)
				return (1);
			head = head->nxt;
			j++;
		}
		buff = head->nxt->data;
		head = head->nxt->nxt;
		i++;
	}
	return (0);
}

/**
 * @brief give each node an index
 * 
 * @details for every possible index (k),
 * find next lowest value in stack_a,
 * assign index
 * 
 * @param head 
 */
void	index_input(t_int_cdll *head)
{
	int idx;
	int min;
	int stack_len;

	stack_len = LST_LEN(head);
	idx = 0;
	min = head->data;
	while (idx < stack_len)
	{
		head = head->nxt;
		while (head->data != min)
		{
			if (head->data < min)
				min = head->data;
			head = head->nxt;
		}
		head->idx = idx;
		while (head->idx != -1)
			head = head->nxt;
		min = head->data;
		idx ++;
	}
}
