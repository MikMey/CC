/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:07 by mimeyer           #+#    #+#             */
/*   Updated: 2026/03/04 20:22:06 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mtrx_isdigit(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j])
		{
			if (j == 0 && (arr[i][j] == '-' || arr[i][j] == '+')
				&& arr[i][j + 1]
				&& ft_isdigit(arr[i][j + 1]))
				j = (int)j;
			else if (!(ft_isdigit(arr[i][j])))
			{
				free_arr(arr);
				throw_error(INPUT_VALUE_ERROR);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

bool	check_i(t_int_cdll *head, int i)
{
	if (i > 2)
		return (0);
	if (head->nxt && head->data > head->nxt->data)
		write(1, "sa\n", 3);
	return (1);
}
