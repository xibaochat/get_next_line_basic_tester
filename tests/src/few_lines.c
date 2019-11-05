#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int get_next_line(int fd, char **line);

int main(int ac, char **av)
{
	(void)ac;
	int fd = open(av[1], O_RDONLY);
	char *line;

	line = NULL;
	get_next_line(fd, &line);
	if (line)
		printf("%s\n", line);
	get_next_line(fd, &line);
	if (line)
		printf("%s\n", line);
	get_next_line(fd, &line);
	if (line)
		printf("%s\n", line);
	return (0);
}
