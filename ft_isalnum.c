/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:17:35 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/12 20:29:48 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (c);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));
// 	// char *test = 0;
// 	int my = ft_isalnum(atoi(argv[1]));
// 	int og = isalnum(atoi(argv[1]));
// 	printf("\nmy: %i\nog: %i\ncompare: %i\n\n",
// 	my, og, memcmp(&my, &og,sizeof(int)));
// }
