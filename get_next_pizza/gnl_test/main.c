
#include "main.h"

f_arr arr[] = {&empty, &fd, &smaller, &bigger, &same, &continues};

int empty(void)
{
	char *files[] = {EMPTY};
	int fd = open(files[0], O_RDONLY);
	char *res = get_next_line(fd);
	close(fd);
	if (*res)
		return (0);
	return (1);
}

int fd(void)
{
	int fd = 10;
	char *res = get_next_line(fd);
	if (*res)
		return (0);
	return (1);
}

int smaller(void)
{
	char *files[] = {BIGGER};
	char *lines[] = {SMALL_LINES};
	int fd;
	char *res;
	for (int i = 0; i < 3; i++)
	{
		fd = open(files[i], O_RDONLY);
		res = get_next_line(fd);
		if (strncmp(res, lines[i], strlen(lines[i])))
		{
			free(res);
			return (0);
		}
		free(res);
		close(fd);
	}
	return (1);
}

int bigger(void)
{
	char *files[] = {SMALLER};
	char *lines[] = {BIG_LINES};
	int fd;
	char *res;
	for (int i = 0; i < 3; i++)
	{
		fd = open(files[i], O_RDONLY);
		res = get_next_line(fd);
		if (strncmp(res, lines[i], strlen(lines[i])))
		{
			free(res);
			return (0);
		}
		free(res);
		close(fd);
	}
	return (1);
}

int same(void)
{
	char *files[] = {SAME};
	char *lines[] = {SAME_LINES};
	int fd;
	char *res;
	for (int i = 0; i < 2; i++)
	{
		fd = open(files[i], O_RDONLY);
		res = get_next_line(fd);
		if (strncmp(res, lines[i], strlen(lines[i])))
		{
			free(res);
			return (0);
		}
		free(res);
		close(fd);
	}
	return (1);
}

int continues(void)
{
	char *lines[] = {CONT_LINES};
	int fd;
	char *res;
	fd = open("get_next_pizza/gnl_test/test_files/continues.txt", O_RDONLY);
	for (int i = 0; i < 5; i++)
	{
		res = get_next_line(fd);
		if (res == NULL)
			return (0);
		printf("%s\n%s\n", res, lines[i]);
		if (strncmp(res, lines[i], strlen(lines[i])))
		{
			free(res);
			return (0);
		}

		free(res);
	}
	close(fd);
	return (1);
}

// int mutiple(void)
// {
// 	char files[] = {MULTIPLE};
// }

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (atoi(argv[0]));
	int i = arr[atoi(argv[1])]();
	return(i);
}
