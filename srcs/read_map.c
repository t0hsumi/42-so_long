#include "../includes/so_long.h"

static void	read_init(t_info *info, int fd)
{
	int		res;
	char	*line;

	res = xget_next_line(fd, &line);
	if (res == 0 || !is_wall(line) || ft_strlen(line) < 3)
	{
		free(line);
		line = NULL;
		write(2, "Error\n\tInvalid map\n", 19);
		exit(1);
	}
	info->col_size = ft_strlen(line);
	info->row_size = 1;
	info->map = xft_strdup(line);
	free(line);
	line = NULL;
}

static void	read_next(t_info *info, int fd)
{
	int		res;
	char	*line;
	char	*tmp;

	res = 1;
	while (res)
	{
		res = xget_next_line(fd, &line);
		if (info->col_size != ft_strlen(line) || (res == 0 && !is_wall(line))
			|| (line[0] != '1' || line[ft_strlen(line) - 1] != '1'))
		{
			free(line);
			line = NULL;
			free(info->map);
			info->map = NULL;
			write(2, "Error\n\tInvalid map\n", 19);
			exit(1);
		}
		info->row_size++;
		tmp = info->map;
		info->map = xft_strjoin(info->map, line);
		my_free(&line, &tmp, NULL, NULL);
	}
}

void	read_map(t_info *info, char *filepath)
{
	int		fd;

	fd = xopen(filepath, O_RDONLY);
	read_init(info, fd);
	read_next(info, fd);
	xclose(fd);
}
