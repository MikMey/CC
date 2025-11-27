/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:01:16 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/12 14:45:23 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (c);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));
// 	// char *test = 0;
// 	int my = ft_isalpha(atoi(argv[1]));
// 	int og = isalpha(atoi(argv[1]));
// 	printf("\nmy: %i\nog: %i\ncompare: %i\n\n",
//		my, og, memcmp(&my, &og,sizeof(int)));
// }
