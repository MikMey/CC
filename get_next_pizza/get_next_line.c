/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:06:48 by mimeyer           #+#    #+#             */
/*   Updated: 2025/12/07 18:59:33 by mimeyer          ###   ########.fr       */
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
		ft_strlcpy_swap(&temp, lst->cache + i, ft_chrxlen(lst->cache, 0, 0, 1) - i + 1);
		free(lst->cache);
		ft_strlcpy_swap(&(lst->cache), temp, ft_chrxlen(temp, 0, 0, 1) + 1);
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
	start = ft_chrxlen(lst->cache, 0, 0, 1);
	if (start == 0)
	{
		lst->cache = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		read(lst->fd, lst->cache, BUFFER_SIZE);
		i++;
	}
	while (!(ft_chrxlen(lst->cache, '\n', start + BUFFER_SIZE * i, 0))
		&& !(ft_chrxlen(lst->cache, '\0', start + BUFFER_SIZE * i, 0)))
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
	unsigned int	i;
	unsigned char	*destt;
	unsigned char	*srcc;

	*dest = ft_calloc(sizeof(char), n + 1);
	if (*dest == 0 || src == 0)
		return (*dest);
	if (*src == '\0')
	{
		**dest = 0;
		return (*dest);
	}
	if (n <= 0)
		return (*dest);
	if (n > ft_chrxlen(src, 0, 0, 1))
		n = ft_chrxlen(src, 0, 0, 1) + 1;
	destt = (unsigned char *)*dest;
	srcc = (unsigned char *)src;
	i = 0;
	while (n > i && (destt != 0 || srcc != 0))
	{
		destt[i] = srcc[i];
		i++;
	}
	return (*dest);
}

size_t ft_chrxlen(const char *s, int c, size_t n, int choose)
{
	size_t	i;

	if (choose == 0)
	{
		i = 0;
		while (i < n)
		{
			if (s[i] == (char) c)
				return (i);
			i++;
		}
		return (0);
	}
	if (s == NULL)
		return(0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

