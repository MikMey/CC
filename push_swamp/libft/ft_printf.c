/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:20:34 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/01 17:23:02 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *pl, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, pl);
	while (pl[i])
	{
		if (pl[i] == '%')
		{
			i++;
			len += flag_master(pl[i], &args);
		}
		else
			len += write(1, &pl[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

int	flag_master(int c, va_list *args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar_fd(va_arg(*args, int), 1);
	else if (c == 's')
		len = ft_putstr_int(va_arg(*args, char *));
	else if (c == '%')
		len = ft_putchar_fd('%', 1);
	else if (c == 'i')
		len = recursive_base(0, va_arg(*args, int), BASE_10, 10);
	else if (c == 'd')
		len = recursive_base(0, va_arg(*args, int), BASE_10, 10);
	else if (c == 'u')
		len = recursive_base(0, va_arg(*args, unsigned int), BASE_10, 10);
	else if (c == 'x')
		len = recursive_base(0, (long long)va_arg(*args, unsigned int), HEX_LOW,
				16);
	else if (c == 'X')
		len = recursive_base(0, (long long)va_arg(*args, unsigned int), HEX_CAP,
				16);
	else if (c == 'p')
		len = put_pointer((unsigned long long)va_arg(*args, void *));
	return (len);
}

int	put_pointer(unsigned long long num_10)
{
	int	len;

	len = 0;
	if (num_10 == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += pointer_recursive_base(0, num_10, HEX_LOW, 16);
	return (len);
}
