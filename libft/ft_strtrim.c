/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:53:43 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/19 17:11:30 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	loop_lower(const char *s1, const char *set, long int lower);
static long int	loop_upper(const char *s1, const char *set, long int lower,
					long int upper);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimmed_str;
	long int	lower;
	long int	upper;

	lower = 0;
	upper = ft_strlen(s1) - 1;
	lower = loop_lower(s1, set, lower);
	upper = loop_upper(s1, set, lower, upper);
	upper++;
	if ((upper - lower) < 0)
		trimmed_str = malloc(sizeof(char) * 1);
	else
		trimmed_str = malloc(sizeof(char) * (upper - lower + 1));
	if (trimmed_str == 0)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + lower, upper - lower + 1);
	return (trimmed_str);
}

static long int	loop_lower(const char *s1, const char *set, long int lower)
{
	size_t	i;

	i = 0;
	while (s1[lower] && set[i])
	{
		if (s1[lower] == set[i])
		{
			lower++;
			i = 0;
		}
		else
			i++;
	}
	return (lower);
}

static long int	loop_upper(const char *s1, const char *set, long int lower,
		long int upper)
{
	size_t	i;

	i = 0;
	while (upper != lower && set[i])
	{
		if (s1[upper] == set[i])
		{
			upper--;
			i = 0;
		}
		else
			i++;
	}
	return (upper);
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
