/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:50:02 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 15:15:27 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_strns(char *ss, char c, size_t strns);
char	**assign_str(char **splitstr, char c, char *ss);

char	**ft_split(char const *s, char c)
{
	char	*ss;
	char	**splitstr;
	size_t	strns;
	char	*cc;

	cc = malloc(sizeof(char) * 2);
	if (cc == 0)
		return (NULL);
	cc[0] = c;
	cc[1] = 0;
	strns = 0;
	ss = ft_strtrim(s, cc);
	if (ss == 0)
		return (NULL);
	strns = check_strns(ss, c, strns);
	splitstr = malloc(sizeof(char *) * (strns + 1));
	if (splitstr == 0)
		return (NULL);
	splitstr[strns] = NULL;
	splitstr = assign_str(splitstr, c, ss);
	free(cc);
	free(ss);
	return (splitstr);
}

size_t	check_strns(char *ss, char c, size_t strns)
{
	size_t	temp_i;
	size_t	i;

	i = 0;
	while (ss[i])
	{
		temp_i = i;
		if (ss[i] != c)
		{
			while (ss[temp_i] != c && ss[temp_i])
				temp_i++;
			i = temp_i - 1;
			strns++;
		}
		i++;
	}
	return (strns);
}

char	**assign_str(char **splitstr, char c, char *ss)
{
	size_t	strns;
	size_t	i;
	size_t	temp_i;

	strns = 0;
	i = 0;
	while (ss[i])
	{
		temp_i = i;
		if (ss[i] != c)
		{
			while (ss[temp_i] != c && ss[temp_i])
				temp_i++;
			splitstr[strns] = malloc(sizeof(char) * (temp_i - i + 1));
			ft_strlcpy(splitstr[strns], ss + i, temp_i - i + 1);
			strns++;
			i = temp_i - 1;
		}
		i++;
	}
	return (splitstr);
}

// int main(int argc, char **argv)
// {
// 	if(argc < 1)
// 		return(atoi(argv[0]));
// 	char **str = ft_split(argv[1], argv[2][0]);
// 	for (int i = 0; str[i] != 0; i++)
// 	{
// 		printf("**%s**\n", str[i]);
// 	}
// 	int i = 0;
// 	while(str[i] != 0)
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }
