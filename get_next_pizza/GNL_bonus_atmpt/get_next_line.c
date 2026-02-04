/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:17:04 by mimeyer           #+#    #+#             */
/*   Updated: 2025/12/14 21:36:04 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_lst	*head;
	t_lst			*node;
	char			*res;

	node = init_lst(&head, fd);
	if (!node)
		return (NULL);
	res = read_fd(&node);
	update_single_node(node); // ← FIXED: Only update THIS node, not all nodes
	return (res);
}
void	update_single_node(t_lst *node) // ← Takes SINGLE node, not list head
{
	size_t i;
	char *tmp;
	if (!node || !node->cache) // Safety check
		return ;
	i = 0;
	while (node->cache[i] && node->cache[i] != '\n')
		i++;
	/* If no '\n' in cache, clear it */
	if (node->cache[i] != '\n')
	{
		free(node->cache);
		node->cache = NULL;
		return ;
	}
	/* Keep only what is after '\n' */
	tmp = NULL;
	tmp = ft_strlcpy_swap(tmp, node->cache + i + 1, ft_strlen(node->cache + i
				+ 1) + 1);
	free(node->cache);
	node->cache = tmp;
	// ← NO LOOP! Only processes this one node
}

t_lst	*init_lst(t_lst **lst, int fd)
{
	t_lst	*node;
	t_lst	*temp;

	temp = *lst;
	while (temp && temp->next && temp->fd != fd)
		temp = temp->next;
	if (!temp || temp->fd != fd)
	{
		node = ft_calloc(sizeof(t_lst), 1);
		node->fd = fd;
		node->next = *lst;
		*lst = node;
		return (node);
	}
	else
		return (temp);
}

/**
 * @brief read from fd with size BS until \\n or end of file
 *
 * @param node 'N' contains fd, cache, * next node
 * @param cache 'C' contains read string
 * @param start 'ST' starting buffer if cache is used with content
 * @param fd 'F' file descriptor
 * @return string to return
 */
char	*read_fd(t_lst **node)
{
	char	*temp;
	int		start;
	int		rd;
	size_t	total_size;

	if (!(*node)->cache)
		(*node)->cache = ft_calloc(BS + 1, sizeof(char));
	if (!(*node)->cache)
		return (NULL);
	start = ft_strlen((*node)->cache);
	if (start > 0 && ft_memchr((*node)->cache, '\n', start))
		return (get_res((*node)->cache));
	temp = ft_strlcpy_swap(NULL, (*node)->cache, start + BS + 1);
	if (!temp)
	{
		free((*node)->cache);
		(*node)->cache = NULL;
		return (NULL);
	}
	free((*node)->cache);
	(*node)->cache = temp;
	total_size = start + BS + 1;
	rd = 1;
	while (rd > 0)
	{
		if ((size_t)start >= total_size - BS)
		{
			temp = ft_strlcpy_swap(NULL, (*node)->cache, start + BS + 1);
			if (!temp)
			{
				free((*node)->cache);
				(*node)->cache = NULL;
				return (NULL);
			}
			free((*node)->cache);
			(*node)->cache = temp;
			total_size = start + BS + 1;
		}
		rd = read((*node)->fd, (*node)->cache + start, BS);
		if (rd == -1)
		{
			free((*node)->cache);
			(*node)->cache = NULL;
			return (NULL);
		}
		if (rd == 0)
			break ;
		(*node)->cache[start + rd] = '\0';
		if (ft_memchr((*node)->cache + start, '\n', rd))
			break ;
		start += rd;
	}
	return (get_res((*node)->cache));
}

char	*get_res(char *cache)
{
	char	*temp;
	int		offset;
	char	*res;

	res = NULL;
	if (!cache || !*cache)
		return (NULL);
	if (MC(C, '\n', ft_strlen(C) + 1))
	{
		temp = ft_memchr(C, '\n', ft_strlen(C) + 1);
		offset = temp - cache;
		res = ft_strlcpy_swap(res, C, offset + 2);
		return (res);
	}
	res = ft_strlcpy_swap(res, C, ft_strlen(C) + 1);
	return (res);
}

void	update_lst(t_lst *lst)
{
	size_t	i;
	char	*temp;
	t_lst	*lst_temp;

	temp = NULL;
	while (lst)
	{
		i = 0;
		lst_temp = lst->next;
		// if (!lst_temp)
		// 	return ;
		while (lst->C && lst->C[i] && lst->C[i] != '\n')
			i++;
		if (lst->C[i] != '\n')
		{
			free(lst->C);
			lst->next = NULL;
			free(lst);
		}
		else
		{
			temp = CPY(temp, lst->C + i + 1, ft_strlen(lst->C) - i);
			free(lst->C);
			lst->C = CPY(lst->C, temp, ft_strlen(temp) + 1);
			free(temp);
		}
		lst = lst_temp;
	}
}
