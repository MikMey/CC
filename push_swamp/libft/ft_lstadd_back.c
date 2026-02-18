/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:23:14 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/18 16:55:22 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst != 0)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	lstnew_add(t_list **head, void *content)
{
	ft_lstadd_back(head, ft_lstnew(content));
}

// int	main(void)
// {
// 	t_list	*list = NULL;
// 	int		len;

// 	// for (int i = argc - 1; i != 0; i--)
// 	// 	ft_lstadd_front(list, ft_lstnew(argv[i]));
// 	ft_lstadd_back(&list, ft_lstnew("Real test"));
// 	len = ft_lstsize(list);
// 	for (int i = 0; i < len; i++)
// 	{
// 		printf("%s\n", (char *)list->content);
// 		list = list->next;
// 	}
// }
