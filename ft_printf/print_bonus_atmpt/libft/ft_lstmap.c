/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:47:09 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 23:04:21 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void delete(void *item);
// void *funct(void *item);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	new_list = NULL;
	if (lst == 0 || f == 0 || del == 0)
		return (new_list);
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}

// void delete(void *item)
// {
// 	if(item)
// 		return ;
// }

// void *funct(void *item)
// {
// 	return(item);
// }

// int	main(int argc, char **argv)
// {
// 	t_list	*list = malloc(sizeof(t_list) * (argc - 1));
// 	int		len;

// 	for (int i = argc - 1; i != 0; i--)
// 		ft_lstadd_front(&list, ft_lstnew(argv[i]));
// 	ft_lstmap(list, &funct, &delete);
// 	len = ft_lstsize(list);
// 	printf("%i\n", len);

// }