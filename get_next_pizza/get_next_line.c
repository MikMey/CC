/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:17:04 by mimeyer           #+#    #+#             */
/*   Updated: 2025/12/13 19:26:28 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_lst	*head;
	t_lst			*node;
	char			*res;

	// if (fd < 0 || BS <= 0 || read(fd, &res, 0) < 0)
	// clear_list(node);
	node = init_lst(&head, fd);
	if (!node)
		return (NULL);
	res = read_fd(&node);
	update_lst(head);
	return (res);
}

t_lst	*init_lst(t_lst **lst, int fd)
{
	t_lst	*node;

	while ((*lst) && (*lst)->next && (*lst)->fd != fd)
		(*lst) = (*lst)->next;
	if (!(*lst) || (*lst)->fd != fd)
	{
		node = ft_calloc(sizeof(t_lst), 1);
		node->fd = fd;
		node->next = *lst;
		*lst = node;
		return (node);
	}
	else
		return (*lst);
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
	int		i;
	int		start;
	int		rd;

	if (!(*N)->C)
		(*N)->C = ft_calloc(sizeof(char), BS);
	i = 0;
	rd = BS;
	start = ft_strlen((*N)->C);
	while (rd != -1 && !MC((*N)->C, '\n', (BS * i) + ST) && rd == BS)
	{
		temp = ft_strlcpy_swap(temp, (*N)->C, ft_strlen((*N)->C) + 1);
		free((*N)->C);
		(*N)->C = ft_strlcpy_swap((*N)->C, temp, ft_strlen(temp) + BS + 1);
		free(temp);
		rd = read((*N)->F, (*N)->C + (BS * i) + ST, BS);
		i++;
	}
	return (get_res((*N)->C));
}

char	*get_res(char *cache)
{
	char	*temp;
	int		offset;
	char	*res;

	res = NULL;
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
		if (!lst_temp)
			return;
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
