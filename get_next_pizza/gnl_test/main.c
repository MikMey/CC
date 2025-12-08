
#include "main.h"

int	main(void)
{
	int fd;
	char *line;

	fd = open("test_files/test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	if (line)
	{
		printf("**%s**\n", line);
		free(line);
	}
	else
		printf("(null)\n");
	if (close(fd) < 0)
	{
		perror("close");
		return (1);
	}
	fd = open("test_files/this.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	if (line)
	{
		printf("**%s**\n", line);
		free(line);
	}
	else
		printf("(null)\n");
	if (close(fd) < 0)
	{
		perror("close");
		return (1);
	}
	return (0);
}
