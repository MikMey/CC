/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:28:49 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/26 17:12:25 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*temp_ptr;

	temp_ptr = (unsigned char *)dest;
	while (len > 0)
	{
		*(temp_ptr++) = (unsigned char)c;
		len--;
	}
	return (dest);
}
