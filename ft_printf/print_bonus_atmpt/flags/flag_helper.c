/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:30:05 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 20:53:21 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../flags.h"

char	*elim_flag(char *pl, int payload_i, int to_elim)
{
	while (pl[payload_i] != '%')
		payload_i -= 1;
	while (!ft_strchr(END_FLAGS, pl[payload_i]))
	{
		if (pl[payload_i] == to_elim)
			pl[payload_i] = 26;
		payload_i += 1;
	}
	if (to_elim == '0')
	{
		while (pl[payload_i] >= '0' && pl[payload_i] <= '9')
		{
			pl[payload_i] = 26;
			payload_i += 1;
		}
	}
	else if (to_elim == ' ')
	{
		while (pl[payload_i] == ' ')
		{
			pl[payload_i] = 26;
			payload_i += 1;
		}
	}
	return (pl);
}
