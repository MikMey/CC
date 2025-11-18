/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:53:43 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 17:49:55 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	*loops(const char *s1, const char *set, long int *limits);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimmed_str;
	long int	*limits;

	limits = malloc(sizeof(size_t) * 2);
	if (limits == 0)
		return (NULL);
	limits[0] = 0;
	limits[1] = ft_strlen(s1) - 1;
	limits = loops(s1, set, limits);
	limits[1]++;
	if ((limits[1] - limits[0]) < 0)
		trimmed_str = malloc(sizeof(char) * 1);
	else
		trimmed_str = malloc(sizeof(char) * (limits[1] - limits[0] + 1));
	if (trimmed_str == 0)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + limits[0], limits[1] - limits[0] + 1);
	free(limits);
	return (trimmed_str);
}

long int	*loops(const char *s1, const char *set, long int *limits)
{
	size_t	i;

	i = 0;
	while (s1[limits[0]] && set[i])
	{
		if (s1[limits[0]] == set[i])
		{
			limits[0]++;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (limits[1] != limits[0] && set[i])
	{
		if (s1[limits[1]] == set[i])
		{
			limits[1]--;
			i = 0;
		}
		else
			i++;
	}
	return (limits);
}

// int main(int argc, char **argv)
// {
// 	if(argc < 2)
// 		return(atoi(argv[0]));
// 	char *res;
// 	res = ft_strtrim(argv[1], argv[2]);
// 	printf("\nres: **%s**\n\n", res);
// 	free(res);
// }
