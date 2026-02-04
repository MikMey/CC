/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:36:23 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 15:01:41 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return ((char *)s + i);
	}
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));
// 	int i = strlen(argv[1]);
// 	// char *s = malloc(sizeof(char *) * (i + 1));
// 	// ft_strlcpy(s, argv[1], i + 1);
// 	char *s = "teste";
// 	char *s1 = malloc(sizeof(char *) * (i + 1));
// 	ft_strlcpy(s1, s, i + 1);
// 	printf("\nmy src: %s\n",  s);

// 	char *my = ft_strchr(s, '\0');
// 	printf("\nmy src: %s\n", s);
// 	char *og = strchr(s1, '\0');
// 	printf("og src: %s\n",  s1);
// 	printf("\nmy: %s\nog: %s\n", my, og);
// 	printf("%p\n%p",s, my);

// 	if(!my || !*my)
// 	{
// 		// free(s);
// 		free(s1);
// 		return(0);
// 	}
// 	printf("compare: %i\n\n",memcmp(my, og, (sizeof(char *) * 10)));
// 	// free(s);
// 	free(s1);
// }
