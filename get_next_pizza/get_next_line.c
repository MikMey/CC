/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:06:48 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/30 22:25:39 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list *lst;
	char *res;
	res = read_until(fd, &lst);
	return(res);
}


char *read_until(int fd, t_list **lst)
{
	int i;
	int size;
	char *temp;

	i = 0;
	init_find_fd(*lst, fd);
	(*lst)->cache = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	size = read((*lst)->fd, (*lst)->cache, BUFFER_SIZE);
	while (!(ft_strchr((*lst)->cache, '\n')) && !(ft_strchr((*lst)->cache, '\0')))
	{
		ft_strlcpy_swap(temp, (*lst)->cache, BUFFER_SIZE * i + 1);
		i++;
		ft_strlcpy_swap((*lst)->cache, temp, BUFFER_SIZE * i + 1);
		size = read((*lst)->fd, (*lst)->cache, BUFFER_SIZE);
	}
}

void	ft_strlcpy_swap(char *dest, char *src, size_t n)
{
	dest = ft_calloc(sizeof(char), n);
	if (dest == 0 || src == 0)
		return (free(src));
	if (*src == '\0')
	{
		*dest = 0;
		return (free(src));
	}
	if (n <= 0)
		return (free(src));
	if (n > ft_strlen(src))
		n = ft_strlen(src) + 1;
	dest = ft_memcpy(dest, src, n);
	dest[n - 1] = '\0';
	return (free(src));
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return ((char *)s + i);
	}
	return (ft_memchr(s, c, ft_strlen(s) + 1));
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
		dest[len] = '\0';
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