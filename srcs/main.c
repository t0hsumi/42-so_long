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
		tmp = xft_strdup(info->map);
		free(info->map);
		info->map = xft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	xclose(fd);
}

int main(int argc, char **argv)
{
	t_info	info;

	check_arg(argc, argv);
	read_map(&info, argv[1]);
	check_map(info);
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
