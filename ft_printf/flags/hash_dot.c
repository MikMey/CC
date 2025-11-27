/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:14:35 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 21:00:14 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

int	hash(va_list args, char *pl, int *payload_i)
{
	int	len;

	va_copy(args, args);
	len = 0;
	if (pl[*payload_i] == 'x' || pl[*payload_i] == 'X')
	{
		write(1, "0x", 2);
		len = 2;
	}
	return (len);
}

int	dot(va_list args, char *pl, int *payload_i)
{
	int	len;
	int	amount;

	len = 0;
	amount = 0;
	while (ft_isdigit(pl[*payload_i]))
	{
		amount *= 10;
		amount += pl[*payload_i] - '0';
		*payload_i += 1;
	}
	len = find_flag(pl, args, payload_i);
	write(1, ".", 1);
	len += amount + 1;
	while (amount-- > 0)
		write(1, "0", 1);
	return (len);
}
