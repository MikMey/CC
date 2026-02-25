/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:42:28 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/25 15:24:26 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				negative;
	long int		num;

	if (*nptr == 0)
		return (0);
	num = 0;
	negative = 0;
	i = 0;
	while (nptr[i] != '\010' && nptr[i] != '\007' && ((nptr[i] > 6
				&& nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		negative = nptr[i++] - '-' + 1;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num *= 10;
		num = num + nptr[i] - 48;
		i++;
	}
	if (negative == 1)
		return (num * -1);
	return (num);
}

int	ft_atoll(const char *nptr)
{
	unsigned int	i;
	int				negative;
	long long int	num;

	if (*nptr == 0)
		return (0);
	num = 0;
	negative = 0;
	i = 0;
	while (nptr[i] != '\010' && nptr[i] != '\007' && ((nptr[i] > 6
				&& nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		negative = nptr[i++] - '-' + 1;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num *= 10;
		num = num + nptr[i] - 48;
		i++;
	}
	if (negative == 1)
		return (num * -1);
	return (num);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[1]));
// 	// char *test = 0;
// 	int my = ft_atoi(" \n 1");
// 	int og = atoi(" \n 1");
// 	printf("\nmy: %i\nog: %i\ncompare: %i\n\n",
// 	my, og, memcmp(&my, &og,sizeof(int)));
// }
