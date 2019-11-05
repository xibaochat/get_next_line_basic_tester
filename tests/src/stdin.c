#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int get_next_line(int fd, char **line);

int main(void)
{
	char *line = NULL;
	int res, old_res;

	old_res = 42;
	while ((res = get_next_line(0, &line))>= 0)
	{
		if (!res && !old_res)
			return (0);
		write(1, line, strlen(line));
		if (res)
			write(1, "\n", 1);
		if (line)
		{
			free(line);
			line = NULL;
		}
		old_res = res;
	}
	return (0);

}
