/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:30:20 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/12 14:45:38 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (c);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));
// 	// char *test = 0;
// 	int my = ft_isprint(atoi(argv[1]));
// 	int og = isprint(atoi(argv[1]));
// 	printf("\nmy: %i\nog: %i\ncompare: %i\n\n",
//	my, og, memcmp(&my, &og,sizeof(int)));
// }
