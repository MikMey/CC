/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:57:41 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/28 02:05:53 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] && (len + i) < n - 1 && n != 0)
	{
		dest[len + i] = src[i];
		i++;
	}
	if (src[i] == '\0' || dest[n - 1] != '\0')
		dest[len + i] = '\0';
	if (len >= n)
		len = n;
	return (len + ft_strlen(src));
}

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return(atoi(argv[1]));

// char *d = malloc(sizeof(char *) * (strlen(argv[1]) + strlen(argv[2]) + 1));
// char *d1 = malloc(sizeof(char *) * (strlen(argv[1]) + strlen(argv[2]) + 1));
// char *d = malloc(sizeof(char) * 14);
// char *d1 = malloc(sizeof(char) * 14);

// strlcpy(d, argv[2], strlen(argv[2]) + 1);
// strlcpy(d1, argv[2], strlen(argv[2]) + 1);

// printf("\nbefore\n\nmy: %s\nog: %s\n", d, d1);

// char d[20];
// char d1[20];
//  d[14] = 'a';
//  d1[14] = 'a';
// size_t n = atoi(argv[3]);
// printf("\nsrc: %lu\ndest: %lu\nn: %lu\n", strlen(argv[1]), strlen(d1), n);
// size_t my = ft_strlcat(d, argv[1], n);
// size_t og = strlcat(d1, argv[1], n);

// printf("\nafter\n\nmy: %s\nog: %s\n", d, d1);
// printf("\nog: %li\nmy: %li\n",og, my);

// if(!d || !(*d))
// {
// 	free(d);
// 	free(d1);
// 	return(0);
// }
// printf("\ntotal: %i\n", memcmp(d, d1, n + 1));
// free(d);
// free(d1);
// }

// valgrind --leak-check=full --track-origins=yes
// --log-file="grind.log" ./libft.a "aaa"
