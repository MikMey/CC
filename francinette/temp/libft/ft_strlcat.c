/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:43:46 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/25 16:45:04 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t d_size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= d_size)
	{
		return (d_size + src_len);
	}
	j = dst_len;
	i = 0;
	while (src[i] && j < d_size - 1)
	{
		dst[j++] = src[i++];
	}
	dst[j] = '\0';
	return (src_len + dst_len);
}
