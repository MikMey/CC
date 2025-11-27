/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:48:36 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 20:54:02 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

char	*convert_base(long long var, const char *base)
{
	int		base_len;
	char	*res;

	base_len = ft_strlen(base);
	res = malloc(sizeof(char) * check_size(var, base_len));
	res[base_len] = 0;
	return (base_recursion(res, var, base, base_len));
}

char	*base_recursion(char *res, long long var, const char *base,
		int base_len)
{
	static int	i;

	if (var / base_len != 0)
		base_recursion(res, var / base_len, base, base_len);
	res[i] = base[var % base_len];
	return (res);
}

int	check_size(long long var, int base_len)
{
	int	len;

	len = 0;
	while (var != 0)
	{
		var /= base_len;
		len++;
	}
	return (len + 1);
}
