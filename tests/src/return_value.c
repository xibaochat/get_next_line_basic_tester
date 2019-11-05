#include "get_next_line.h"

int main(int ac, char **av)
{
	(void)ac;
	int fd = open(av[1], O_RDONLY);
	char *line = NULL;

	return (get_next_line(fd, &line));
}
