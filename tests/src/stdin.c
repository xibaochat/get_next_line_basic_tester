#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int get_next_line(int fd, char **line);

void free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int main(void)
{
	char *line = NULL;
	int res, old_res;

	old_res = 42;
	while ((res = get_next_line(0, &line))>= 0)
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
