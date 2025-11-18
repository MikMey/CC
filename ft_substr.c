/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:03:01 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 18:05:37 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*strsup;

	if (s == 0 || start > ft_strlen(s))
	{
		strsup = malloc(sizeof(char));
		*strsup = '\0';
		return (strsup);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	strsup = malloc(sizeof(char) * (len + 1));
	if (strsup == 0)
		return (NULL);
	if (!(*s))
	{
		*strsup = 0;
		return (strsup);
	}
	ft_strlcpy(strsup, s + (start * (len / len)), len + 1);
	return (strsup);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[0]));
// 	char *sub = ft_substr("", 1, 1);
// 	printf("\n%s\n%i\n\n", sub, memcmp("", sub, 2));
// 	write(1, &sub, 8);
// 	free(sub);
// }
