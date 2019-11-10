#include "get_next_line_bonus.h"
#include <string.h>

int main(int ac, char **av)
{
	(void)ac;
	int fd0 = open(av[1], O_RDONLY);
	int fd1 = open(av[2], O_RDONLY);
	int fdo0 = open("output_f0", O_WRONLY|O_CREAT, 0644);
	int fdo1 = open("output_f1", O_WRONLY|O_CREAT, 0644);
	int res0 = 1;
	int res1 = 1;
	char *line0 = NULL;
	char *line1 = NULL;


	while ((res0 > 0) || (res1 > 0))
	{
		if (res0)
			res0 = get_next_line(fd0, &line0);
		if (res1)
			res1 = get_next_line(fd1, &line1);
		if (line0)
		{
			write(fdo0, line0, strlen(line0));
			if (res0)
				write(fdo0, "\n", 1);
			free(line0);
			line0 = NULL;
		}
		if (line1)
		{
			write(fdo1, line1, strlen(line1));
			if (res1)
				write(fdo1, "\n", 1);
			free(line1);
			line1 = NULL;
		}
	}
	return (0);
}
