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
	info->mlx_win = xmlx_new_window(info->mlx, info->col_size * 64, info->row_size * 64, "so_long");
	info->image[COLLECTIBLE] = xmlx_xpm_file_to_image(info->mlx, "./img/collectible.xpm", &width, &height);
	info->image[EMPTY] = xmlx_xpm_file_to_image(info->mlx, "./img/empty.xpm", &width, &height);
	info->image[EXIT] = xmlx_xpm_file_to_image(info->mlx, "./img/exit.xpm", &width, &height);
	info->image[PLAYER] = xmlx_xpm_file_to_image(info->mlx, "./img/player.xpm", &width, &height);
	info->image[WALL] = xmlx_xpm_file_to_image(info->mlx, "./img/wall.xpm", &width, &height);
	info->x = (ft_strchr(info->map, 'P') - info->map) % info->col_size;
	info->y = (ft_strchr(info->map, 'P') - info->map) / info->col_size;
	info->move_count = 0;
}

int draw_map(t_info *info)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (info->map[++i])
	{
		map_to_pos(i, info->col_size, &x, &y);
		if (info->map[i] == '0')
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->image[EMPTY], 64 * x, 64 * y);
		else if (info->map[i] == '1')
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->image[WALL], 64 * x, 64 * y);
		else if (info->map[i] == 'C')
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->image[COLLECTIBLE], 64 * x, 64 * y);
		else if (info->map[i] == 'E')
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->image[EXIT], 64 * x, 64 * y);
		else if (info->map[i] == 'P')
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->image[EMPTY], 64 * x, 64 * y);
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->image[PLAYER], 64 * info->x, 64 * info->y);
	return (0);
}

void	clear_game(t_info *info)
{
	(void)info;
	exit(0);
}

void	player_move(int keycode, t_info *info)
{
	int next_x;
	int next_y;

	if (keycode == A || keycode == D)
	{
		next_y = info->y;
		if (keycode == A)
			next_x = info->x - 1;
		else
			next_x = info->x + 1;
	}
	if (keycode == W || keycode == S)
	{
		next_x = info->x;
		if (keycode == W)
			next_y = info->y - 1;
		else
			next_y = info->y + 1;
	}
	if (info->map[info->col_size * next_y + next_x] == '0')
	{
		info->x = next_x;
		info->y = next_y;
		printf("%d\n", ++(info->move_count));
	}
	else if (info->map[info->col_size * next_y + next_x] == 'C')
	{
		info->x = next_x;
		info->y = next_y;
		info->map[info->col_size * next_y + next_x] = '0';
		printf("%d\n", ++(info->move_count));
	}
	else if (info->map[info->col_size * next_y + next_x] == 'E')
	{
		info->map[info->col_size * next_y + next_x] = '0';
		clear_game(info);
	}
	else if (info->map[info->col_size * next_y + next_x] == 'P')
	{
		info->x = next_x;
		info->y = next_y;
		info->map[info->col_size * next_y + next_x] = '0';
		printf("%d\n", ++(info->move_count));
	}
	draw_map(info);
}

void	exit_game(t_info *info)
{
	(void)info;
	exit(0);
}

int	img_change(int keycode, t_info *info)
{
	if (keycode == A || keycode == S || keycode == D || keycode == W)
		player_move(keycode, info);
	else if (keycode == ESC)
		exit_game(info);
	return (0);
}

int main(int argc, char **argv)
{
	t_info	info;

	check_arg(argc, argv);
	read_map(&info, argv[1]);
	check_map(info);
	init_str(&info);
	draw_map(&info);
	mlx_key_hook(info.mlx_win, img_change, &info);
	mlx_loop(info.mlx);
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
