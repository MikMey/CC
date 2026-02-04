/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:27:01 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/13 13:11:02 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return(atoi(argv[0]));

// 	char my = ft_toupper(argv[1][0]);
// 	char og = toupper(argv[1][0]);

// 	printf("\nmy: %c\nog: %c\n", my, og);

// 	printf("\ntotal: %i\n\n", my - og);

// }