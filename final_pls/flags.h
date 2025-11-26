/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:03:09 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/26 13:30:36 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "structs.h"

# define FLAGS "-.0 #+duipscXx%\0"
# define END_FLAGS "duipscXx%\0"

char			*dash(va_list args, const char *pl, int *payload_i);
char			*dot(va_list args, const char *pl, int *payload_i);
char			*zero(va_list args, const char *pl, int *payload_i);
char			*space(va_list args, const char *pl, int *payload_i);
char			*d(va_list args, const char *pl, int *payload_i);
char			*u(va_list args, const char *pl, int *payload_i);
char			*i(va_list args, const char *pl, int *payload_i);
char			*hash(va_list args, const char *pl, int *payload_i);
char			*p(va_list args, const char *pl, int *payload_i);
char			*s(va_list args, const char *pl, int *payload_i);
char			*c(va_list args, const char *pl, int *payload_i);
char			*upper_x(va_list args, const char *pl, int *payload_i);
char			*lower_x(va_list args, const char *pl, int *payload_i);
char			*percent(va_list args, const char *pl, int *payload_i);
char			*plus(va_list args, const char *pl, int *payload_i);

typedef char	*(*t_flags)(va_list, const char *, int *);

int				flag_master(const char *pl, va_list args);
int				flag_loop(const char *pl, int *payload_i, va_list args);
int				free_all(void *ptr, ...);
int				find_flag(const char *pl, va_list args, int *payload_i);
char			*call_funct(int idx, va_list args, const char *pl,
					int *payload_i);
t_flags			*get_functions(void);

// # define DASH &dash
// # define DOT &dot
// # define ZERO &zero
// # define SPACE &space
// # define D &d
// # define U &u
// # define I &i
// # define HASH &hash
// # define P &p
// # define S &s
// # define C &c
// # define UPPER_X &upper_x
// # define LOWER_X &lower_x
// # define PERCENT &percent
// # define PLUS &plus

// # define FLAG_FUNCS DASH,
// 					DOT,
// 					ZERO,
// 					SPACE,
// 					HASH,
// 					PLUS,
// 					D,
// 					U,
// 					I,
// 					P,
// 					S,
// 					C,
// 					UPPER_X,
// 					LOWER_X,
// 					PERCENT,
// 					NULL

#endif
