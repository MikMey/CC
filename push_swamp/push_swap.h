/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:27:29 by mimeyer           #+#    #+#             */
/*   Updated: 2026/02/04 17:39:37 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"

# define MALLOC_ERROR "ERROR\nMalloc failed to allocate; terminating\n"
# define INPUT_VALUE_ERROR "ERROR\nInput arguments are bad; terminating\n"
# define INPUT_ERROR "ERROR\nInput is bad; terminating\n"
# define NULL_POINTER "ERROR\nNull pointer exception error; terminating\n" 

int main(int argc, char** argv);
void	throw_error(char *s);

#endif
