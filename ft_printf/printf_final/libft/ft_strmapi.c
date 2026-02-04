/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:03:28 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 15:11:12 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (s == 0)
		return (NULL);
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == 0)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, (char)s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
