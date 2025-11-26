/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:20:02 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 17:51:46 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (ss1[i] == ss2[i] && (n - 1) > i)
		i++;
	return (ss1[i] - ss2[i]);
}

// int main(int argc, char ** argv)
// {
// 	if (argc < 2)
// 		return(atoi(argv[0]));

// 	int my = ft_memcmp(argv[1], argv[2], 4);
// 	int og = memcmp(argv[1], argv[2], 4);

// 	printf("\nmy: %i\nog: %i\n", my, og);
// 	printf("\ntotal: %i\n", memcmp(&my, &og, sizeof(int)));
// }
