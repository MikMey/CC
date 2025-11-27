/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:28:58 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 17:49:00 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i_big;
	unsigned int	little_len;

	if (*little == 0)
		return ((char *)big);
	i_big = 0;
	little_len = ft_strlen(little);
	while (big[i_big] && len > (i_big + little_len - 1))
	{
		if (ft_strncmp(big + i_big, little, little_len) == 0)
			return ((char *)big + i_big);
		i_big++;
	}
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return(atoi(argv[0]));

// 	// char *temp = 0;

// 	char *my = ft_strnstr(argv[1], argv[2], 5);
// 	char *og = strnstr(argv[1], argv[2], 5);

// 	printf("\nmy: %s\nog: %s\n", my, og);

// 	if(!my ||!(*my))
// 		return(0);

// 	printf("\ntotal: %i\n\n", memcmp(my, og, strlen(og) + 1));

// }
