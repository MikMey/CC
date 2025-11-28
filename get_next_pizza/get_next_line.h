/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:07:02 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/28 21:40:05 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*malloc_buffer(char **buf, size_t i);
char	*read_until(int fd, char **buf);
void	free_arr(char **buf);
size_t	ft_strlcpy(char *dest, const char **src, size_t n);
char	*malloc_res(size_t size, char **buf);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t n);

#endif
