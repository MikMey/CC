/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:28:00 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/13 13:10:00 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return(atoi(argv[0]));

// 	char my = ft_tolower(argv[1][0]);
// 	char og = tolower(argv[1][0]);

// 	printf("\nmy: %c\nog: %c\n", my, og);

// 	printf("\ntotal: %i\n\n", my - og);

// }
