#include "../includes/so_long.h"

int	xopen(const char *pathname, int flags)
{
	int	fd;

	fd = open(pathname, flags);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	return (fd);
}

int	xget_next_line(int fd, char **line)
{
	int	res;

	res = get_next_line(fd, line);
	if (res == -1)
	{
		perror("get_next_line");
		exit(1);
	}
	return (res);
}
