/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:06:48 by mimeyer           #+#    #+#             */
/*   Updated: 2025/11/28 20:52:33 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char **buf;
	char *res;

	buf = malloc(sizeof(char *));
	if(!buf)
	{
		free(buf);
		return(NULL);
	}
	res = read_until(fd, buf);
	free_arr(buf);
	return(res);
}


char *read_until(int fd, char **buf)
{
	static size_t i;
	size_t iter_idx;
	char *res;
	long int size;
	
	if(malloc_buffer(buf, i) == 0)
			return(NULL);
	iter_idx = 0;
	size = read(fd, buf[i], BUFFER_SIZE);
	while (size > 0)
	{
		while (buf[i][iter_idx] != '\n' && buf[i][iter_idx++]);
		if(iter_idx != BUFFER_SIZE - 1)
			break;
		iter_idx = 0;
		i++;
		if(malloc_buffer(buf, i) == 0)
			return(NULL);
		read(fd, buf[i], BUFFER_SIZE);
	}
	if (size == -1)
		return(NULL);
	res = malloc_res(iter_idx, buf);
	ft_strlcpy(res, buf[i], iter_idx + 2);
	return (res);
}

void free_arr(char **buf)
{
	size_t i;
	
	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
	return ;
}

int main(void)
{
    // int fd;
    char *line;

    // fd = open("test.txt", O_RDONLY);
    // if (fd < 0)
    // {
    //     perror("open");
    //     return (1);
    // }
    line = get_next_line(0);
    if (line)
    {
        printf("%s\n", line);
        free(line);
    }
    // else
    //     printf("(null)\n");
    // if (close(fd) < 0)
    // {
    //     perror("close");
    //     return (1);
    // }
    return (0);
}