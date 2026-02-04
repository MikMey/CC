/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:20:47 by mimeyer           #+#    #+#             */
/*   Updated: 2026/01/30 12:15:53 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "structs.h"

# define HEX_CAP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# define BASE_10 "0123456789"

int	ft_printf(const char *pl, ...);
int	flag_master(int c, va_list *args);
int	recursive_base(int len, long long num_10, const char *base,
		const int base_len);
int	put_pointer(unsigned long long num_10);
int	pointer_recursive_base(int len, unsigned long long num_10, const char *base,
		const int base_len);

#endif
