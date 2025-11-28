/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:10:39 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/28 20:52:38 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	if (dest == 0 || src == 0)
		return (ft_strlen(src));
	if (*src == '\0')
	{
		*dest = 0;
		return (ft_strlen(src));
	}
	if (n <= 0)
		return (ft_strlen(src));
	if (n > ft_strlen(src))
		n = ft_strlen(src) + 1;
	dest = ft_memcpy(dest, src, n);
	dest[n - 1] = '\0';
	return (ft_strlen(src));
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

	res = malloc(sizeof(char) * (size + 2));
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
	buf[i] = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
	{
		free_arr(buf);
		return (NULL);
	}
	return (*buf);
}
