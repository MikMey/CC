/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:30:26 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/26 17:18:02 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (!dest && !src)
		return (NULL);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (n--)
	{
		*temp_dest++ = *temp_src++;
	}
	return (dest);
}
