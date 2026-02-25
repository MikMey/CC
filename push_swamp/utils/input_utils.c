/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:07 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 19:17:18 by mimeyer          ###   ########.fr       */
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
			if (j == 0 && (arr[i][j] == '-' || arr[i][j] == '+'))
				continue ;
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
