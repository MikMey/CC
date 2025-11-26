/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %_plus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:58:38 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 14:31:07 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

char	*percent(va_list args, const char *pl, int *payload_i)
{
	char	*temp;

	if (!pl)
		pl = (char *)args;
	temp = ft_calloc(sizeof(char), 2);
	temp[0] = '%';
	return (temp);
}

char	*plus(va_list args, const char *pl, int *payload_i)
{
	char	*s1;
	char	*s2;
	char	*temp;
	va_list	copy;

	va_copy(copy, args);
	s1 = ft_calloc(sizeof(char), 2);
	if (va_arg(copy, long long) > 0)
		s1[0] = '+';
	va_end(copy);
	s2 = call_funct(ft_idxstrchr(FLAGS, *(pl + 1)), args, pl + 1, payload_i);
	temp = ft_strjoin(s1, s2);
	free_all(s1, s2);
	return (temp);
}
