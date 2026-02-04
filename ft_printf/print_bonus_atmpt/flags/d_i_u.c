/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:59:11 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 21:01:00 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

int	d(va_list args, char *pl, int *payload_i)
{
	if (!pl[*payload_i])
		return (0);
	return (ft_putstr_int(ft_itoa(va_arg(args, int))));
}

int	u(va_list args, char *pl, int *payload_i)
{
	if (!pl[*payload_i])
		return (0);
	return (ft_putstr_int(convert_base(va_arg(args, unsigned int),
				"0123456789")));
}

int	i(va_list args, char *pl, int *payload_i)
{
	if (!pl[*payload_i])
		return (0);
	return (ft_putstr_int(ft_itoa(va_arg(args, int))));
}
