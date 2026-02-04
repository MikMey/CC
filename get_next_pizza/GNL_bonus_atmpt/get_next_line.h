/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:17:06 by mimeyer           #+#    #+#             */
/*   Updated: 2025/12/14 21:34:57 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define BS BUFFER_SIZE
# define N node
# define C cache
# define F fd
# define MC ft_memchr
# define CPY ft_strlcpy_swap
# define ST start

typedef struct s_lst
{
	char			*cache;
	int				fd;
	struct s_lst	*next;
}					t_lst;

char				*get_next_line(int fd);
t_lst				*init_lst(t_lst **lst, int fd);
char				*read_fd(t_lst **node);
char				*get_res(char *CH);
void				update_single_node(t_lst *node);

void				*ft_calloc(size_t nmemb, size_t size);
size_t				ft_strlen(const char *s);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strlcpy_swap(char *dest, char *src, size_t n);

#endif