/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:47:34 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 17:49:18 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;

	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (copy == 0)
		return (NULL);
	ft_strlcpy(copy, s, ft_strlen(s) + 1);
	return (copy);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[0]));
// 	char *my = ft_strdup((char *) "coucou");
// 	// char *og = strdup((char *) "coucou");
// 	// printf("\nmy: %s\nog: %s\n\n", my, og);
// 	// printf("total: %i\n\n", memcmp(my, og, strlen(argv[1]) + 1));
// 	printf("\n%i\n\n", memcmp((char *) "coucou", my, strlen("coucou" + 1)));
// 	free(my);
// 	// free(og);
// }
