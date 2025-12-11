/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:10:39 by mimeyer           #+#    #+#             */
/*   Updated: 2025/12/11 16:55:35 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_find_fd(t_list **lst, int fd)
{
	t_list	*new_node;

	if ((*lst) == NULL)
	{
		(*lst) = ft_calloc(sizeof(t_list), 1);
		if ((*lst) == NULL)
			return ;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		(*lst)->fd = fd;
		return ;
	}
	while ((*lst)->fd != fd && (*lst)->next != NULL)
		(*lst) = (*lst)->next;
	if ((*lst)->fd != fd)
	{
		new_node = ft_calloc(sizeof(t_list), 1);
		if (new_node == NULL)
			return ;
		new_node->prev = (*lst)->prev;
		new_node->next = (*lst);
		(*lst)->prev = new_node;
		new_node->fd = fd;
		(*lst) = new_node;
	}
}

void	free_node(t_list **node)
{
	t_list	*temp;

	if ((*node)->cache)
		free((*node)->cache);
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	if ((*node)->prev)
		(*node)->prev->next = (*node)->next;
	temp = (*node)->next;
	free(*node);
	*node = temp;
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
