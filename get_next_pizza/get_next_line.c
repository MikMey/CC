/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:06:48 by mimeyer           #+#    #+#             */
/*   Updated: 2025/12/04 18:25:17 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*res;

	res = read_until(fd, lst);
	return (res);
}

char	*split_first(t_list *lst, size_t size)
{
	size_t		i;
	char	*res;
	char	*temp;

	i = 0;
	res = NULL;
	temp = NULL;
	while (lst->cache[i] != '\n' && size > i && lst->cache[i])
		i++;
	ft_strlcpy_swap(&res, lst->cache, i + 1);
	if (res[i] != '\0')
	{
		ft_strlcpy_swap(&temp, lst->cache + i, ft_strlen(lst->cache) - i + 1);
		free(lst->cache);
		ft_strlcpy_swap(&(lst->cache) + i, temp, ft_strlen(temp) + 1);
		free(temp);
	}
	else
		free_node(lst);
	return (res);
}

char	*read_until(int fd, t_list *lst)
{
	int		i;
	char	*temp;
	int		start;

	i = 0;
	init_find_fd(&lst, fd);
	start = ft_strlen(lst->cache);
	if (start == 0)
	{
		lst->cache = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		read(lst->fd, lst->cache, BUFFER_SIZE);
		i++;
	}
	while (!(ft_memchr(lst->cache, '\n', start + BUFFER_SIZE * i))
		&& !(ft_memchr(lst->cache, '\0', start + BUFFER_SIZE * i)))
	{
		temp = ft_strlcpy_swap(&temp, lst->cache, start + BUFFER_SIZE * i + 1);
		free(lst->cache);
		i++;
		ft_strlcpy_swap(&(lst->cache), temp, start + BUFFER_SIZE * i + 1);
		free(temp);
		read(lst->fd, lst->cache + (start + BUFFER_SIZE * (i - 1)),
			BUFFER_SIZE);
	}
	return (split_first(lst, start + BUFFER_SIZE * i));
}

char *ft_strlcpy_swap(char **dest, char *src, size_t n)
{
	*dest = ft_calloc(sizeof(char), n);
	if (*dest == 0 || src == 0)
		return (*dest);
	if (*src == '\0')
	{
		**dest = 0;
		return (*dest);
	}
	if (n <= 0)
		return (*dest);
	if (n > ft_strlen(src))
		n = ft_strlen(src) + 1;
	*dest = ft_memcpy(*dest, src, n);
	*dest[n - 1] = '\0';
	return (*dest);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
		{
			s = ss;
			return (&ss[i]);
		}
		i++;
	}
	return (NULL);
}

int	main(void)
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
// clear && gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 get_next_line*.c
// valgrind --leak-check=full --log-file=grind.log ./a.out
