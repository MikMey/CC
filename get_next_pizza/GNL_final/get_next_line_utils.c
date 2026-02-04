/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:37:01 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/02 19:37:41 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (NULL);
	while (i < (size * nmemb))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_realloc(char **src, size_t size)
{
	size_t	i;
	char	*dest;

	if (!(*src))
		return (NULL);
	if (!(**src))
		return (free(*src), NULL);
	dest = ft_calloc(sizeof(char), size + 1);
	i = 0;
	while (size > i && (*src)[i])
	{
		dest[i] = (*src)[i];
		i++;
	}
	if (*src)
		free(*src);
	*src = NULL;
	return (dest);
}
