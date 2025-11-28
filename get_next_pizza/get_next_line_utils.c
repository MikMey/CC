/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:10:39 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/28 21:24:13 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char **src, size_t n)
{
	int i;

	i = 0;
	while(ft_strlen(dest) != n - 1 && src[i])
	{
		ft_strlcat(dest, src[i], ft_strlen(src[i]) + ft_strlen(dest) + 1);
		i++;
	}
	return(i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*destt;
	unsigned char	*srcc;

	destt = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	i = 0;
	while (n > i && (destt != 0 || srcc != 0))
	{
		destt[i] = srcc[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *malloc_res(size_t size, char **buf)
{
	char *res;

	res = ft_calloc(sizeof(char), (size + 2));
	if (!res)
	{
		free_arr(buf);
		free(res);
		return(NULL);
	}
	return(res);
}


char *malloc_buffer(char **buf, size_t i)
{
	buf[i] = ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!buf)
	{
		free_arr(buf);
		return (NULL);
	}
	return (*buf);
}
