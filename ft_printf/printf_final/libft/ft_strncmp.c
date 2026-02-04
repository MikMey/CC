/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:55:51 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 17:48:55 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && (unsigned char)s1[i]
		&& (unsigned char)s2[i] && (n - 1) > i)
		i++;
	if (((unsigned char)s1[i] - (unsigned char)s2[i]) > 0)
		return (1);
	else if (((unsigned char)s1[i] - (unsigned char)s2[i]) < 0)
		return (-1);
	else
		return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));

// 	// char *temp = 0;

// 	int my = ft_strncmp("test\200", "test\0", 6);
// 	int og = strncmp("test\200", "test\0", 6);

// 	printf("\nmy: %i\nog: %i\n", my, og);

// 	printf("\ntotal: %i\n\n", my - og);

// }
