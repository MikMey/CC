/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:20:34 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/25 12:32:05 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *pl, ...)
{
	va_list	args;

	va_start(args, pl);
	flag_master(pl, args);
	va_end(args);
	return (0);
}
