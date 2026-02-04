/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:32 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/04 18:45:15 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char** argv)
{
	int i;
	char *input;

	i = 1;
	input = NULL;
	if (argc <= 0)
		throw_error(INPUT_ERROR);
	else if (argc > 2)
	{
		while(argc > i)
		{
			if (!argv[i] || !*(argv[i]))
				throw_error(INPUT_VALUE_ERROR);
			input = ft_strjoin(&input, argv[i], " ");
			if (input == NULL)
				throw_error(MALLOC_ERROR);
			i++;
		}
	}
	else if( !argv[1] || !*(argv[1]))
		throw_error(INPUT_VALUE_ERROR);
	else
	{
		input = ft_calloc(sizeof(char), ft_strlen(argv[1]) + 1);
		ft_strlcpy(input, argv[1], ft_strlen(argv[1]) + 1);
	}
	ft_printf("%s\n", input);
}

void	throw_error(char *s)
{
	write(2, &s, ft_strlen(s) + 1);
	exit(0);
}
