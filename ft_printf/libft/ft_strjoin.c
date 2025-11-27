/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:38:23 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/17 19:37:19 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	newstr = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (newstr == 0)
		return (NULL);
	if (s1 == 0)
		ft_strlcpy(newstr, s2, len_s2 + 1);
	else if (s2 == 0)
		ft_strlcpy(newstr, s1, len_s1 + 1);
	else
	{
		ft_strlcpy(newstr, s1, len_s1 + 1);
		ft_strlcat(newstr, s2, len_s1 + len_s2 + 1);
	}
	return (newstr);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[0]));
// 	char *newstr = ft_strjoin(argv[1], argv[2]);
// 	printf("\nres: %s\n\n", newstr);
// 	free(newstr);
// }
