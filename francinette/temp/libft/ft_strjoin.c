/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:20:06 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/26 17:18:54 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*results;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	results = malloc(strlen(s1) + strlen(s2) + 1);
	if (!results)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		results[j++] = s1[i++];
	i = 0;
	while (s2[i])
		results[j++] = s2[i++];
	results[j] = '\0';
	return (results);
}
