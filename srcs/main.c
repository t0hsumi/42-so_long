#include "../includes/so_long.h"

void	read_map(t_info *info, char *filepath)
{
	int	fd;
	int	res;
	char *line;
	char	*tmp;

	fd = xopen(filepath, O_RDONLY);
	res = xget_next_line(fd, &line);
	if (res == 0 || !is_wall(line))
	{
		write(2, "Error\n\tInvalid map", 18);
		exit(1);
	}
	info->col_size = ft_strlen(line);
	info->row_size = 1;
	info->map = xft_strdup(line);
	free(line);
	while (res)
	{
		res = xget_next_line(fd, &line);
		if (info->col_size != ft_strlen(line) || (res == 0 && !is_wall(line))
			|| (line[0] != '1' || line[ft_strlen(line) - 1] != '1'))
		{
			write(2, "Error\n\tInvalid map", 18);
			exit(1);
		}
		info->row_size++;
		tmp = xft_strdup(info->map);
		free(info->map);
		info->map = xft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	xclose(fd);
}

void	init_str(t_info *info)
{
	int height;
	int width;

	info->mlx = xmlx_init();
	info->mlx_win = xmlx_new_window(info->mlx, info->row_size * 64, info->col_size * 64, "so_long");
	info->collectible = xmlx_xpm_file_to_image(info->mlx, "./img/collectible.xpm", &width, &height);
	info->empty = xmlx_xpm_file_to_image(info->mlx, "./img/empty.xpm", &width, &height);
	info->exit = xmlx_xpm_file_to_image(info->mlx, "./img/exit.xpm", &width, &height);
	info->player = xmlx_xpm_file_to_image(info->mlx, "./img/player.xpm", &width, &height);
	info->wall = xmlx_xpm_file_to_image(info->mlx, "./img/wall.xpm", &width, &height);
	info->x = (ft_strchr(info->map, 'P') - info->map) % info->col_size;
	info->y = (ft_strchr(info->map, 'P') - info->map) / info->col_size;
	info->move_count = 0;
}

int main(int argc, char **argv)
{
	t_info	info;

	check_arg(argc, argv);
	read_map(&info, argv[1]);
	check_map(info);
	init_str(&info);
	printf("%s", info.map);
	printf("(%d, %d)\n", info.x, info.y);
	free(info.map);
}

/* typedef struct	s_vars { */
/* 	void	*mlx; */
/* 	void	*win; */
/* }				t_vars; */

/* int mouse_hook(int button, int x, int y, void *param) */
/* { */
/* 	(void)button; */
/* 	(void)param; */
/* 	printf("x = %d, y = %d\n", x, y); */
/* 	return (0); */
/* } */

/* int	main(void) */
/* { */
/* 	t_vars	vars; */

/* 	vars.mlx = mlx_init(); */
/* 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!"); */
/* 	mlx_mouse_hook(vars.win, mouse_hook, &vars); */
/* 	mlx_loop(vars.mlx); */
/* } */
