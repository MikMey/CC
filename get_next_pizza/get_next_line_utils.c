/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:10:39 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/30 22:10:43 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char **src, size_t n)
{
	int i;

	i = 0;
	while(ft_strlen(dest) != n - 1 && src[i])
	{
		ft_strlcat(dest, src[i], ft_strlen(dest) + n);
		i++;
	}
	return(i);
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
	buf[i] = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
	{
		free_arr(buf);
		return (NULL);
	}
	return (*buf);
}

void	init_find_fd(t_list *lst, int fd)
{
	t_list *new_node;

	if (lst == NULL)
	{
		lst = ft_calloc(sizeof(t_list), 1);
		if (lst == NULL)
			return ;
		lst->next = NULL;
		lst->prev = NULL;
		lst->fd = fd;
		return ;
	}
	while (lst->fd != fd && lst->next != NULL)
		lst = lst->next;
	if (lst->fd != fd)
	{
		new_node = ft_calloc(sizeof(t_list), 1);
		if (new_node == NULL)
			return ;
		new_node->prev = lst->prev;
		new_node->next = lst;
		lst->prev = new_node;
		new_node->fd = fd;
		lst = new_node;
	}
}
