/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:31:23 by kmurched          #+#    #+#             */
/*   Updated: 2025/11/26 17:19:44 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
		{
			res = (char *)&s[i];
		}
		i++;
	}
	if (cc == '\0')
		res = (char *)&s[i];
	return (res);
}
