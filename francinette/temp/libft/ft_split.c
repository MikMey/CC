/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 21:07:11 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/23 21:46:25 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	safe_malloc(char **token_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (token_v[position] == NULL)
	{
		while (i < position)
			free(token_v[i++]);
		free(token_v);
		return (1);
	}
	return (0);
}

static size_t	count_tokens(char const *s, char delimiter)
{
	size_t	tokens;
	int		inside_token;

	tokens = 0;
	while (*s)
	{
		inside_token = 0;
		while (*s == delimiter && *s)
			s++;
		while (*s != delimiter && *s)
		{
			if (!inside_token)
			{
				tokens++;
				inside_token = 1;
			}
			s++;
		}
	}
	return (tokens);
}

static void	copy_word(char **token_v, const char *s, size_t len, int i)
{
	size_t	j;

	j = 0;
	while (j < len)
	{
		token_v[i][j] = (s - len)[j];
		j++;
	}
	token_v[i][j] = '\0';
}

static int	fill(char **token_v, const char *s, char delimiter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimiter && *s)
			s++;
		while (*s != delimiter && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_malloc(token_v, i, len + 1))
				return (1);
			copy_word(token_v, s, len, i);
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**token_v;

	if (s == NULL)
		return (NULL);
	tokens = count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (token_v == NULL)
		return (NULL);
	if (fill(token_v, s, c))
		return (NULL);
	token_v[tokens] = NULL;
	return (token_v);
}
