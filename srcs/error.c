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

int xclose(int fd)
{
	if (close(fd) == -1)
	{
		perror("close");
		exit(1);
	}
	return (0);
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

char	*xft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
	{
		perror("ft_strdup");
		exit(1);
	}
	ft_memcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}

char	*xft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (!res)
	{
		perror("ft_strjoin");
		exit(1);
	}
	return (res);
}

void	*xmlx_init()
{
	void	*res;

	res = mlx_init();
	if (!res)
	{
		perror("mlx_init");
		exit(1);
	}
	return (res);
}

void	*xmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	void	*res;

	res = mlx_new_window(mlx_ptr, size_x, size_y, title);
	if (!res)
	{
		perror("mlx_new_window");
		exit(1);
	}
	return (res);
}
