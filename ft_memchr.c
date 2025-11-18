/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:05:23 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/17 13:44:18 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
		{
			s = ss;
			return (&ss[i]);
		}
		i++;
	}
	return (NULL);
}

// int	main(int argc, char **argv)
// {
// 	// char	*s;
// 	char	*my;
// 	char	*og;

// 	if (argc < 1)
// 		return (atoi(argv[1]));
// 	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
// 	// s = malloc(sizeof(char *) * (strlen(argv[1]) + 1));
// 	// ft_strlcpy(s, argv[1], strlen(argv[1]) + 1);
// 	my = ft_memchr(tab, -1, 7);
// 	og = memchr(tab, -1, 7);
// 	printf("\nmy: %s\nog: %s\n", my, og);
// 	if(!my || !*my)
// 	{
// 		// free(s);
// 		return(0);
// 	}
// 	printf("compare: %i\n\n", memcmp(my, og, (sizeof(char *) * 5)));
// 	// free(s);
// }
