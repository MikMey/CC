/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:06:48 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/28 20:51:11 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char **buf;
	char *res;

	buf = malloc(sizeof(char *));
	if(!buf)
	{
		free(buf);
		return(NULL);
	}
	res = read_until(fd, buf);
	free_arr(buf);
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
		while (buf[i][iter_idx] != '\n' && buf[i][iter_idx++]);
		if(iter_idx != BUFFER_SIZE - 1)
			break;
		iter_idx = 0;
		i++;
		if(malloc_buffer(buf, i) == 0)
			return(NULL);
		read(fd, buf[i], BUFFER_SIZE);
	}
	if (size == -1)
		return(NULL);
	res = malloc_res(iter_idx, buf);
	ft_strlcpy(res, buf[i], iter_idx + 2);
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

int main(void)
{
    // int fd;
    char *line;

    // fd = open("test.txt", O_RDONLY);
    // if (fd < 0)
    // {
    //     perror("open");
    //     return (1);
    // }
    line = get_next_line(0);
    if (line)
    {
        printf("%s\n", line);
        free(line);
    }
    // else
    //     printf("(null)\n");
    // if (close(fd) < 0)
    // {
    //     perror("close");
    //     return (1);
    // }
    return (0);
}