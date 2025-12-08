/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:07:02 by mimeyer           #+#    #+#             */
/*   Updated: 2025/12/06 21:05:33 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*cache;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

char				*get_next_line(int fd);
char				*read_until(int fd, t_list *lst);
void				*ft_calloc(size_t nmemb, size_t size);
char				*split_first(t_list *lst, size_t size);
char				*ft_strlcpy_swap(char **dest, char *src, size_t n);
size_t				ft_chrxlen(const char *s, int c, size_t n, int choose);
void				free_node(t_list *node);
void				init_find_fd(t_list **lst, int fd);

#endif
