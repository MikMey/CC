/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:02:49 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/27 13:59:05 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

/**
 * @brief act uppon flag or write string
 *
 * @return len of print
 */
int	flag_master(const char *pl, va_list args)
{
	int	*payload_i;
	int	len;

	payload_i = malloc(sizeof(int));
	if (!payload_i)
		return (free_all(payload_i));
	*payload_i = 0;
	len = 0;
	while (pl[*payload_i])
	{
		if (pl[*payload_i] == '%')
			len = find_flag(pl + *payload_i + 1, args, payload_i);
		else
		{
			ft_putchar_fd(pl[*payload_i], 1);
			len += 1;
		}
		*payload_i += 1;
	}
	return (len);
}

int	find_flag(const char *pl, va_list args, int *payload_i)
{
	int	len;

	len = 0;
	while (ft_strchr(FLAGS, *pl))
	{
		len += call_funct(ft_idxstrchr(FLAGS, *pl), args, pl, payload_i);
		if (ft_strchr(END_FLAGS, *pl))
			break ;
	}
	return (len);
}

int	call_funct(int idx, va_list args, const char *pl, int *payload_i)
{
	static t_flags	*funct_arr;

	if (!funct_arr)
		funct_arr = get_functions();
	if (!funct_arr)
	{
		free_all(funct_arr);
		return (0);
	}
	*payload_i += 1;
	return (funct_arr[idx](args, (char *)pl, payload_i));
}

t_flags	*get_functions(void)
{
	t_flags	*funct_arr;

	funct_arr = malloc(sizeof(t_flags) * 16);
	ft_memcpy(funct_arr, (t_flags[]){&dash, &dot, &zero, &space, &plus, &d, &u,
		&i, &hash, &p, &s, &c, &upper_x, &lower_x, &percent, NULL},
		sizeof(funct_arr) * 16);
	return (funct_arr);
}

int	free_all(void *ptr, ...)
{
	va_list	args;
	void	*temp;

	va_start(args, ptr);
	temp = va_arg(args, void *);
	while (temp)
	{
		free(temp);
		temp = va_arg(args, void *);
	}
	free(ptr);
	return (0);
}
