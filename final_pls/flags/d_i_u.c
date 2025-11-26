/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:59:11 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 14:30:57 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

char	*d(va_list args, const char *pl, int *payload_i)
{
}

char	*u(va_list args, const char *pl, int *payload_i)
{
}

char	*i(va_list args, const char *pl, int *payload_i)
{
	char *res;
	
	res = ft_itoa(va_arg(args, int));
	return (res);
}
