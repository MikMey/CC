/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unify_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:30:50 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/15 18:30:45 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
