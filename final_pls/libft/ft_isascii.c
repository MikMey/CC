/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:25:00 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/12 14:45:29 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 128 && c >= 0)
		return (1);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));
// 	// char *test = 0;
// 	int my = ft_isascii(atoi(argv[1]));
// 	int og = isascii(atoi(argv[1]));
// 	printf("\nmy: %i\nog: %i\ncompare: %i\n\n",
//	my, og, memcmp(&my, &og,sizeof(int)));
// }
