/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:33:37 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/05 16:31:21 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return(atoi(argv[1]));

// 	char *temp = 0;

// 	size_t my = ft_strlen(temp);
// 	size_t og = strlen(temp);

// 	printf("\nmy: %lu\nog: %lu\n", my, og);

// 	printf("\ntotal: %lu\n\n", my - og);

// }
