/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:20:16 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/26 17:19:49 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in(const char *str, char c)
{
	while (*str && c != *str)
		str++;
	return (c == *str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = strlen(s1);
	while (in(set, s1[start]))
		start++;
	if (start >= end)
		return (ft_strdup(""));
	while (in(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
