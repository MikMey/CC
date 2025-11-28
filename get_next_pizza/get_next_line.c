/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:06:48 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/28 21:31:21 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char **buf;
	char *res;

	buf = ft_calloc(sizeof(char *), 10);
	if(!buf)
	{
		free(buf);
		return(NULL);
	}
	res = read_until(fd, buf);
	free_arr(buf);
	return(res);
}


char *read_until(int fd, char **buf)
{
	static size_t i;
	size_t iter_idx;
	char *res;
	long int size;
	
	if(malloc_buffer(buf, i) == 0)
			return(NULL);
	iter_idx = 0;
	size = read(fd, buf[i], BUFFER_SIZE);
	while (size > 0)
	{
		while (iter_idx < BUFFER_SIZE && buf[i][iter_idx] != '\n' && buf[i][iter_idx++]);
		if(iter_idx != BUFFER_SIZE)
			break;
		iter_idx = 0;
		i++;
		if(malloc_buffer(buf, i) == 0)
			return(NULL);
		read(fd, buf[i], BUFFER_SIZE);
	}
	if (size == -1)
		return(NULL);
	res = malloc_res((iter_idx + 1) * (i + 1), buf);
	ft_strlcpy(res, (const char **)buf, ((iter_idx + 1) * (i + 1) + 1));
	return (res);
}

void free_arr(char **buf)
{
	size_t i;
	
	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
	return ;
}

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

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] && (len + i) < n - 1 && n != 0)
	{
		dest[len + i] = src[i];
		i++;
	}
	if (src[i] == '\0' || dest[n - 1] != '\0')
		dest[len + i] = '\0';
	if (len >= n)
		len = n;
	return (len + ft_strlen(src));
}

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }
    line = get_next_line(fd);
    if (line)
    {
        printf("**%s**\n", line);
        free(line);
    }
    else
        printf("(null)\n");
    if (close(fd) < 0)
    {
        perror("close");
        return (1);
    }
    return (0);
}