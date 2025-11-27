/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:38:31 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 17:46:16 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		ss[i] = (unsigned char)c;
		i++;
	}
	s = ss;
	return (s);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));
// 	char *s = malloc(sizeof(char *) * (strlen(argv[1]) + 1));
// 	char *s1  = malloc(sizeof(char *) * (strlen(argv[1]) + 1));

// 	memcpy(s, argv[1], strlen(argv[1]) + 1);
// 	memcpy(s1, s, strlen(s) + 1);

// 	char *my = ft_memset(s, 'a', strlen(s));
// 	printf("\nmy src: %s\n",  s);
// 	char *og = memset(s1, 'a', strlen(s1));
// 	printf("og src: %s\n", s1);
// 	printf("\nmy: %s\nog: %s\n", my, og);
// 	if(!my || !*my)
// 	{
// 		free(s);
// 		free(s1);
// 		return(0);
// 	}
// 	printf("compare: %i\n\n",memcmp(my, og, strlen(og) + 1));
// 	free(s);
// 	free(s1);
// }
