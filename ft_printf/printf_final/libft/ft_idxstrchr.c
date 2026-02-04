/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idxstrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:01:00 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/25 12:04:37 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_idxstrchr(const char *s, int c)
{
	if (c == 0)
		return (-1);
	return (ft_idxmemchr(s, c, ft_strlen(s) + 1));
}
