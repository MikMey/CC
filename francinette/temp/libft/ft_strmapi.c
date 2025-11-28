/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:25:58 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/26 17:13:30 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*results;
	size_t			len;

	if (!s | !f)
		return (NULL);
	len = ft_strlen(s);
	results = malloc((len + 1) * sizeof(char));
	if (!results)
		return (results);
	if (!s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		results[i] = f(i, s[i]);
		i++;
	}
	results[i] = '\0';
	return (results);
}
