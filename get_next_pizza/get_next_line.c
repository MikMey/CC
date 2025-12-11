/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:17:04 by mimeyer           #+#    #+#             */
/*   Updated: 2025/12/11 20:08:48 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_lst	*head;
	t_lst			*node;
	char			*res;

	node = init_lst_fd(&head, head, fd);
	if (!node)
		return (NULL);
	res = read_fd(&node);
	update_node(&node, head);
	return (res);
}

t_lst	*init_lst_fd(t_lst **head, t_lst *lst, int fd)
{
	t_lst	*node;

	while (lst && lst->next && lst->fd != fd)
		lst = lst->next;
	if (!lst || lst->fd != fd)
	{
		node = ft_calloc(sizeof(t_lst), 1);
		node->fd = fd;
		node->next = *head;
	}
	else
		node = lst;
	if (!head || !(*head))
		head = &node;
	return (node);
}

char	*read_fd(t_lst **node)
{
	char	*temp;
	int		i;
	int		start;
	int		rd;

	if (!(*N)->C)
		(*N)->C = ft_calloc(sizeof(char), BUFFER_SIZE);
	i = 0;
	rd = 0;
	start = ft_strlen((*N)->C) + 1;
	while (rd != -1 && !MC((*N)->C, '\n', (BS * i) + ST) && !MC((*N)->C, '\0',
			(BS * i) + ST))
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

char	*get_res(char *CH)
{
	char	*temp;
	int		offset;
	char	*res;

	res = NULL;
	if (MC(CH, '\n', ft_strlen(CH) + 1))
	{
		temp = ft_memchr(CH, '\n', ft_strlen(CH) + 1);
		offset = CH - temp;
		res = ft_strlcpy_swap(res, CH, offset + 1);
		return (res);
	}
	res = ft_strlcpy_swap(res, CH, ft_strlen(CH) + 1);
	return (res);
}

void	update_node(t_lst **node, t_lst *lst)
{
	int		i;
	char	*temp;

	temp = NULL;
	i = 0;
	while ((*N)->C[i] && (*N)->C[i] != '\n')
		i++;
	if ((*N)->C[i] != '\n')
	{
		free((*N)->C);
		while (lst && lst->next != *node)
			lst = lst->next;
		if (lst)
			lst->next = (*node)->next;
		free(*node);
		return ;
	}
	temp = ft_strlcpy_swap(temp, (*N)->C + i + 1, ft_strlen((*N)->C) - i);
	free((*N)->C);
	(*N)->C = ft_strlcpy_swap((*N)->C, temp, ft_strlen(temp) + 1);
	free(temp);
}
