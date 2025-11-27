/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:03:09 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 21:25:57 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "structs.h"

# define FLAGS "-.0 #+duipscXx%\0"
# define END_FLAGS "duipscXx%\0"

int			dash(va_list args, char *pl, int *payload_i);
int			dot(va_list args, char *pl, int *payload_i);
int			zero(va_list args, char *pl, int *payload_i);
int			space(va_list args, char *pl, int *payload_i);
int			d(va_list args, char *pl, int *payload_i);
int			u(va_list args, char *pl, int *payload_i);
int			i(va_list args, char *pl, int *payload_i);
int			hash(va_list args, char *pl, int *payload_i);
int			p(va_list args, char *pl, int *payload_i);
int			s(va_list args, char *pl, int *payload_i);
int			c(va_list args, char *pl, int *payload_i);
int			upper_x(va_list args, char *pl, int *payload_i);
int			lower_x(va_list args, char *pl, int *payload_i);
int			percent(va_list args, char *pl, int *payload_i);
int			plus(va_list args, char *pl, int *payload_i);

typedef int	(*t_flags)(va_list, char *, int *);

int			flag_master(const char *pl, va_list args);
int			free_all(void *ptr, ...);
int			find_flag(const char *pl, va_list args, int *payload_i);
int			call_funct(int idx, va_list args, const char *pl, int *payload_i);
t_flags		*get_functions(void);

char		*convert_base(long long var, const char *base);
char		*base_recursion(char *res, long long var, const char *base,
				int base_len);
int			check_size(long long var, int base_len);
char		*elim_flag(char *pl, int payload_i, int to_elim);

#endif
