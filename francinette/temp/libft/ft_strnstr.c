/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:44:29 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/26 17:19:32 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && big[i + j] && j + i < len)
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
