/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:45:25 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 17:48:45 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			last = i;
		i++;
	}
	if ((unsigned char)c == 0 && s[i] == 0)
		last = i;
	if (last == -1)
		return (NULL);
	return ((char *)(s + last));
}

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return(atoi(argv[0]));

// 	char *my = ft_strrchr(argv[1], 0);
// 	char *og = strrchr(argv[1], 0);

// 	printf("\nmy: %s\nog: %s\n", my, og);

// 	if(!my ||!(*my))
// 		return(0);

// 	printf("\ntotal: %i\n\n", memcmp(my, og, strlen(og) + 1));

// }
