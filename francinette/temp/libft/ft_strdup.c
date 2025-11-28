/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:17:36 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/26 18:05:59 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*destination;
	size_t	i;

	i = 0;
	if (!*s1)
	{
		destination = malloc(1);
		*destination = '\0';
		return (destination);
	}
	destination = (char *)malloc(ft_strlen(s1) + 1);
	if (!destination)
		return (NULL);
	while (s1[i])
	{
		destination[i] = s1[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}
