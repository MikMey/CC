/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:32 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/13 13:02:30 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**arr_input;
	t_int_CDLL	*lst_nums;
	int		i;

	arr_input = ft_split(unify_input(argc, argv), ' ');
	lst_nums = NULL;
	i = 0;
	while (arr_input[i])
		add_int_CDLL(&lst_nums, atoi(arr_input[i++]));

}

void add_int_CDDL(t_int_CDLL **head, int data)
{
	t_int_CDLL *node;

	node = new_int_CDDL_node(data);
	if (!(*head))
		*head = node;
	else
	{
		node->prev = (*head)->prev;
		node->nxt = *head;
		(*head)->prev = node;
	}
	
}

t_int_CDLL *new_int_CDDL_node(int data)
{
	t_int_CDLL *node;

	node = malloc(sizeof(t_int_CDLL));
	if (!node)
		throw_error(MALLOC_ERROR);
	node->nxt = NULL;
	node->prev = NULL;
	node->data = data;
	return(node);
}

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

void	throw_error(char *s)
{
	ft_printf(BOLD_RED);
	write(2, s, ft_strlen(s) + 1);
	ft_printf(RESET_COLOR);
	exit(0);
}
