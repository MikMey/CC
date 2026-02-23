/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:34:43 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/23 21:18:52 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief error to standard error and exit
 *
 * @param s message
 */
void	throw_error(char *s)
{
	ft_printf(BOLD_RED);
	write(2, s, ft_strlen(s) + 1);
	ft_printf(RESET_COLOR);
	exit(0);
}

void	throw_arr(char *s, char **arr)
{
	free_arr(arr);
	throw_error(s);
}

void	throw_arr_cdll(char *s, char **arr, t_int_cdll **head)
{
	free_arr(arr);
	free_int_cdll(head);
	throw_error(s);
}

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
	}
	free(arr);
	return ;
}
