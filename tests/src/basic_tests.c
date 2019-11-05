#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int get_next_line(int fd, char **line);

static void free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int main(int ac, char **av)
{
	(void)ac;
	int fd = open(av[1], O_RDONLY);
	char *line = NULL;
	int res, old_res;

	old_res = 42;
	while ((res = get_next_line(fd, &line))>= 0)
	{
		if (!res && !old_res)
		{
			free_str(&line);
			return (0);
		}
		write(1, line, strlen(line));
		if (res)
			write(1, "\n", 1);
		if (line)
			free_str(&line);
		old_res = res;
	}
	return (0);

}
