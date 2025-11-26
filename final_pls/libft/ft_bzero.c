/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:56:00 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 17:46:23 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main(int argc, char ** argv)
// {
// 	if (argc < 2)
// 		return(atoi(argv[0]));

// 	char *s = malloc(sizeof(char *) * (strlen(argv[1]) + 1));
// 	char *s1 = malloc(sizeof(char *) * (strlen(argv[1]) + 1));

// 	memcpy(s, argv[1], 1);
// 	memcpy(s1, argv[1], 1);

// 	ft_bzero(s, strlen(s) + 1);
// 	bzero(s1, strlen(s1) + 1);

// 	printf("\nmy: %s\nog: %s\n", s, s1);
// 	printf("\ntotal: %i\n", memcmp(s,s1, strlen(argv[1]) + 1));
// 	free(s);
// 	free(s1);
// }
