/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:58:38 by mimeyer           #+#    #+#             */
/*   Updated: 2026/01/27 17:28:10 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	recursive_base(int len, long long num_10, const char *base,
		const int base_len)
{
	int	minus;

	minus = 0;
	if (num_10 < 0)
	{
		minus += write(1, "-", 1);
		num_10 *= -1;
	}
	if (num_10 / base_len > 0)
		len += recursive_base(len, num_10 / base_len, base, base_len);
	len += ft_putchar_fd(base[num_10 % base_len], 1);
	return (len + minus);
}

int	pointer_recursive_base(int len, unsigned long long num_10, const char *base,
		const int base_len)
{
	if (num_10 / base_len > 0)
		len += pointer_recursive_base(len, num_10 / base_len, base, base_len);
	len += ft_putchar_fd(base[num_10 % base_len], 1);
	return (len);
}
