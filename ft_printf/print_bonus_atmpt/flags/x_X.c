/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_X.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:18:32 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 20:54:42 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

int	upper_x(va_list args, char *pl, int *payload_i)
{
	if (!pl[*payload_i])
		return (0);
	return (ft_putstr_int(convert_base(va_arg(args, int), "0123456789ABCDEF")));
}

int	lower_x(va_list args, char *pl, int *payload_i)
{
	if (!pl[*payload_i])
		return (0);
	return (ft_putstr_int(convert_base(va_arg(args, int), "0123456789abcdef")));
}
