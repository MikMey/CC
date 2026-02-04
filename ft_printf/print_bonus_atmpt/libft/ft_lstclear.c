/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:04:41 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 21:40:02 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void delete(void *item);

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		size;
	t_list	*next;

	size = ft_lstsize(*lst);
	while (size > 0)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
		size--;
	}
}
// void delete(void *item)
// {
// 	if(item)
// 		return ;
// }

// int	main(int argc, char **argv)
// {
// 	t_list	*list = malloc(sizeof(t_list) * (argc - 1));
// 	int		len;

// 	for (int i = argc - 1; i != 0; i--)
// 		ft_lstadd_front(&list, ft_lstnew(argv[i]));
// 	ft_lstclear(&list, &delete);
// 	len = ft_lstsize(list);
// 	printf("%i\n", len);

// }
