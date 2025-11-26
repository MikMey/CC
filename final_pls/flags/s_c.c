/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:15:49 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 14:33:21 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

char	*s(va_list args, const char *pl, int *payload_i)
{
	char	*res;
	char	*temp;

	if (!pl)
		pl = pl;
	res = va_arg(args, char *);
	temp = ft_calloc(sizeof(char), ft_strlen(res));
	ft_strlcpy(temp, res, ft_strlen(res) + 1);
	return (temp);
}

char	*c(va_list args, const char *pl, int *payload_i)
{
	char	*temp;

	if (!pl)
		pl = pl;
	temp = ft_calloc(sizeof(char), 2);
	temp[0] = va_arg(args, char);
	return (temp);
}
