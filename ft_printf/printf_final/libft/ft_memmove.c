/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:00:17 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 17:59:14 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destt;
	const unsigned char	*srcc;
	size_t				i;

	destt = (unsigned char *)dest;
	srcc = (const unsigned char *)src;
	i = 0;
	if (destt < srcc)
	{
		while (i < n && (destt != 0 || srcc != 0))
		{
			destt[i] = srcc[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0 && (destt != 0 || srcc != 0))
		{
			i--;
			destt[i] = srcc[i];
		}
	}
	return (dest);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[0]));
// 	// char *d;
// 	// char *d1;
// 	char *s = malloc(sizeof(char *) * (11));
// 	char *s1 = malloc(sizeof(char *) * (11));
// 	// // s += 1;
// 	// // d = s - 1;
// 	// // s1 += 1;
// 	// // d1 = s1 - 1;
// 	strlcpy(s, "abc-", strlen("abc-") + 1);
// 	strlcpy(s1, "abc-", strlen("abc-") + 1);

// 	char *my = ft_memmove(s + 1, s, 2);
// 	printf("\nmy dest: %s\nmy src: %s\n", s, s);

// 	char *og = memmove(s1 + 1, s1, 2);
// 	printf("\nog dest: %s\nog src: %s\n", s1, s1);
// 	printf("\nmy: %s\nog: %s\n", my, og);

// 	s -= 1;
// 	s1 -= 1;
// 	printf("compare: %i\n\n",memcmp(my, og, strlen(og) + 1));
// 	free(s);
// 	free(s1);
// }
