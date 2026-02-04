
#include "main.h"

f_arr arr[] = {&empty, &fd, &smaller, &bigger, &same, &continues, &multiple};

int empty(void)
{
	char *files[] = {EMPTY};
	int fd = open(files[0], O_RDONLY);
	char *res = get_next_line(fd);
	close(fd);
	if (res && *res)
	{
		free(res);
		return (0);
	}
	free(res);
	return (1);
}

int fd(void)
{
	int fd = 10;
	char *res = get_next_line(fd);
	if (res && *res)
	{
		free(res);
		return (0);
	}
	free(res);
	return (1);
}

int smaller(void)
{
	char *files[] = {BIGGER};
	char *lines[] = {SMALL_LINES};
	int* fd = calloc(3, sizeof(int));
	char *res;
	for (int i = 0; i < 3; i++)
	{
		fd[i] = open(files[i], O_RDONLY);
		res = get_next_line(fd[i]);
		if (memcmp(res, lines[i], strlen(lines[i])))
			FR_CUR;
		free(res);
		res = get_next_line(fd[i]);
		free(res);
	}
	for (int i = 0; i < 3; i++)
		close(fd[i]);
	free(fd);
	return (1);
}

int bigger(void)
{
	char *files[] = {SMALLER};
	char *lines[] = {BIG_LINES};
	int* fd = calloc(3, sizeof(int));
	char *res;
	for (int i = 0; i < 3; i++)
	{
		fd[i] = open(files[i], O_RDONLY);
		res = get_next_line(fd[i]);
		if (memcmp(res, lines[i], strlen(lines[i])))
			FR_CUR;
		free(res);
		res = get_next_line(fd[i]);
		free(res);
	}
	for (int i = 0; i < 3; i++)
		close(fd[i]);
	free(fd);
	return (1);
}

int same(void)
{
	char *files[] = {SAME};
	char *lines[] = {SAME_LINES};
	int* fd = calloc(3, sizeof(int));
	char *res;
	for (int i = 0; i < 2; i++)
	{
		fd[i] = open(files[i], O_RDONLY);
		res = get_next_line(fd[i]);
		if (memcmp(res, lines[i], strlen(lines[i])))
			FR_CUR;
		free(res);
		res = get_next_line(fd[i]);
		free(res);
	}
	for (int i = 0; i < 3; i++)
		close(fd[i]);
	free(fd);
	return (1);
}

int continues(void)
{
	char *lines[6] = {CONT_LINES};
	int fd;
	char *res;
	fd = open("/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/continues.txt", O_RDONLY);
	for (int i = 0; i < 6; i++)
	{
		res = get_next_line(fd);
		if (res == NULL)
			return (0);
		if (memcmp(res, lines[i], strlen(lines[i])))
		{
			free(res);
			return (0);
		}
		free(res);
	}
	close(fd);
	return (1);
}

int multiple(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line;
	char ***lines = calloc(sizeof(char **), 4);
	char *temp1[] = {TEXT};
	char *temp2[] = {CAT};
	char *temp3[] = {DOG};
	char *temp4[] = {FISH};
	lines[0] = temp1;
	lines[1] = temp2;
	lines[2] = temp3;
	lines[3] = temp4;
	fd1 = open("/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/texts.txt", O_RDONLY);
	fd2 = open("/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/cats.txt", O_RDONLY);
	fd3 = open("/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/dogs.txt", O_RDONLY);
	fd4 = open("/home/mimeyer/Desktop/CC_git/get_next_pizza/gnl_test/test_files/fish.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
		return (0);
	for (int x = 0; x < 3; x++)
	{
		line = get_next_line(fd1);
		if (memcmp(line, lines[0][x], strlen(lines[0][x])))
			FR_MULT_RET;
		printf("fd1:'%s'\n", line);
		free(line);
		line = get_next_line(fd2);
		if (memcmp(line, lines[1][x], strlen(lines[1][x])))
			FR_MULT_RET;
		printf("fd2:'%s'\n", line);
		free(line);
		line = get_next_line(fd3);
		if (memcmp(line, lines[2][x], strlen(lines[2][x])))
			FR_MULT_RET;
		printf("fd3:'%s'\n", line);
		free(line);
		line = get_next_line(fd4);
		if (memcmp(line, lines[3][x], strlen(lines[3][x])))
			FR_MULT_RET;
		printf("fd4:'%s'\n", line);
		free(line);
	}
	free(lines);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (atoi(argv[0]));
	int i = arr[atoi(argv[1])]();
	return(i);
}
