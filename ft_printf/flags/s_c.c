/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:15:49 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 20:58:59 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

int	s(va_list args, char *pl, int *payload_i)
{
	if (!pl[*payload_i])
		return (0);
	return (ft_putstr_int(va_arg(args, char *)));
}

int	c(va_list args, char *pl, int *payload_i)
{
	char	ch;

	if (!pl[*payload_i])
		return (0);
	ch = va_arg(args, int);
	write(1, &ch, 1);
	return (1);
}
