/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idxmemchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:01:02 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/25 12:04:42 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_idxmemchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}
