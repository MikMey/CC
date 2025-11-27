/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   -_0_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:56:10 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 21:01:40 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

int	dash(va_list args, char *pl, int *payload_i)
{
	va_copy(args, args);
	pl = elim_flag(pl, *payload_i, '0');
	return (0);
}

int	zero(va_list args, char *pl, int *payload_i)
{
	int		amount;
	int		len;
	char	*match;

	va_copy(args, args);
	match = "diuxX";
	amount = atoi(pl + *payload_i);
	while (pl[*payload_i] >= '0' && pl[*payload_i] <= '9')
		*payload_i += 1;
	while (*match)
	{
		if (*match == pl[*payload_i])
			break ;
		match++;
		if (!*match)
			return (0);
	}
	len = amount;
	while (amount > 0)
	{
		write(1, "0", 1);
		amount--;
	}
	return (len);
}

int	space(va_list args, char *pl, int *payload_i)
{
	int	len;

	va_copy(args, args);
	len = 1;
	write(1, " ", 1);
	while (pl[*payload_i] == ' ')
	{
		write(1, " ", 1);
		*payload_i += 1;
		len++;
	}
	return (len);
}
