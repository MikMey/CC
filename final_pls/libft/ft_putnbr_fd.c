/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:30:26 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/18 16:26:35 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nn;

	nn = (long)n;
	if (nn < 0)
	{
		nn *= -1;
		ft_putchar_fd('-', fd);
	}
	if ((nn / 10) != 0)
		ft_putnbr_fd(nn / 10, fd);
	ft_putchar_fd((nn % 10) + '0', fd);
}

// int main(int argc, char **argv)
// {
// 	if (argc < 1)
// 		return(atoi(argv[0]));
// 	ft_putnbr_fd(atoi(argv[1]), 1);
// }
