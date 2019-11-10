#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int get_next_line(int fd, char **line);

void print_and_free(char **line)
{
	if (*line)
	{
		printf("%s\n", *line);
		free(*line);
		*line = NULL;
	}
}

int main(int ac, char **av)
{
	(void)ac;
	int fd = open(av[1], O_RDONLY);
	char *line;

	line = NULL;
	get_next_line(fd, &line);
	print_and_free(&line);
	get_next_line(fd, &line);
	print_and_free(&line);
	get_next_line(fd, &line);
	print_and_free(&line);
	close(fd);
	return (0);
}
