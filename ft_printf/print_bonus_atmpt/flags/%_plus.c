/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %_plus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:58:38 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 21:28:38 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

int	percent(va_list args, char *pl, int *payload_i)
{
	if (!pl[*payload_i])
		return (0);
	va_copy(args, args);
	return (ft_putstr_int("%"));
}

int	plus(va_list args, char *pl, int *payload_i)
{
	int		len;
	va_list	copy;

	len = 0;
	va_copy(copy, args);
	if (va_arg(copy, long long) > 0)
		len += ft_putstr_int("+");
	va_end(copy);
	len += call_funct(ft_idxstrchr(FLAGS, *(pl + 1)), args, pl + 1, payload_i);
	return (len);
}
