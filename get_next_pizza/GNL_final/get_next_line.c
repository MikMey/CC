/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:30:10 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/03 15:19:40 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	static int	first;
	size_t		i;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (first == 1 && buffer == NULL)
		return (NULL);
	first = 1;
	buffer = grow_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	res = finish_buffer(&buffer, i);
	return (res);
}

char	*grow_buffer(int fd, char *buffer)
{
	int		status;
	size_t	i;

	i = 0;
	status = BUFFER_SIZE;
	if (!buffer)
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!(*buffer))
		status = read(fd, buffer, BUFFER_SIZE);
	while (status == BUFFER_SIZE)
	{
		while (buffer && buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer && (buffer[i] == '\n' || status == 0))
			return (buffer);
		buffer = ft_realloc(&buffer, BUFFER_SIZE + i);
		status = read(fd, buffer + i, BUFFER_SIZE);
	}
	while (buffer && buffer[i] && buffer[i] != '\n' && status != -1)
		i++;
	if (status != -1 && buffer && (buffer[i] == '\0' || buffer[i] == '\n'))
		return (buffer);
	return (free(buffer), NULL);
}

char	*finish_buffer(char **buffer, size_t key_idx)
{
	char	*res;
	size_t	i;

	if ((*buffer)[key_idx] == '\0')
		return (ft_realloc(buffer, key_idx));
	i = 0;
	res = malloc(sizeof(char) * (key_idx + 2));
	while (i <= key_idx)
	{
		res[i] = (*buffer)[i];
		i++;
	}
	res[i] = '\0';
	i = 0;
	while ((*buffer)[key_idx + 1 + i])
	{
		(*buffer)[i] = (*buffer)[key_idx + 1 + i];
		i++;
	}
	while ((*buffer)[i])
		(*buffer)[i++] = 0;
	return (res);
}
