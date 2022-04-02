#include "../includes/so_long.h"

void	init_str(t_info *info)
{
	int	height;
	int	width;

	info->mlx = xmlx_init();
	info->mlx_win = xmlx_new_window(info->mlx, \
	info->col_size * 64, info->row_size * 64, "so_long");
	info->image[COLLECTIBLE] = xmlx_xpm_file_to_image(info->mlx, \
	"./img/collectible.xpm", &width, &height);
	info->image[EMPTY] = xmlx_xpm_file_to_image(info->mlx, \
	"./img/empty.xpm", &width, &height);
	info->image[EXIT] = xmlx_xpm_file_to_image(info->mlx, \
	"./img/exit.xpm", &width, &height);
	info->image[PLAYER] = xmlx_xpm_file_to_image(info->mlx, \
	"./img/player.xpm", &width, &height);
	info->image[WALL] = xmlx_xpm_file_to_image(info->mlx, \
	"./img/wall.xpm", &width, &height);
	info->x = (ft_strchr(info->map, 'P') - info->map) % info->col_size;
	info->y = (ft_strchr(info->map, 'P') - info->map) / info->col_size;
	info->move_count = 0;
	count_collectible(info);
}

int	draw_map(t_info *info)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (info->map[++i])
	{
		map_to_pos(i, info->col_size, &x, &y);
		if (info->map[i] == '0')
			mlx_put_image_to_window(info->mlx, \
			info->mlx_win, info->image[EMPTY], 64 * x, 64 * y);
		else if (info->map[i] == '1')
			mlx_put_image_to_window(info->mlx, \
			info->mlx_win, info->image[WALL], 64 * x, 64 * y);
		else if (info->map[i] == 'C')
			mlx_put_image_to_window(info->mlx, \
			info->mlx_win, info->image[COLLECTIBLE], 64 * x, 64 * y);
		else if (info->map[i] == 'E')
			mlx_put_image_to_window(info->mlx, \
			info->mlx_win, info->image[EXIT], 64 * x, 64 * y);
		else if (info->map[i] == 'P')
			mlx_put_image_to_window(info->mlx, \
			info->mlx_win, info->image[PLAYER], 64 * x, 64 * y);
	}
	return (0);
}

void	clear_game(t_info *info)
{
	int	i;

	free(info->map);
	info->map = NULL;
	mlx_destroy_window(info->mlx, info->mlx_win);
	info->mlx_win = NULL;
	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(info->mlx, info->image[i]);
		info->image[i++] = NULL;
	}
	mlx_destroy_display(info->mlx);
	info->mlx = NULL;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	check_arg(argc, argv);
	read_map(&info, argv[1]);
	check_map(info);
	init_str(&info);
	mlx_hook(info.mlx_win, 02, 1L << 0, img_change, &info);
	mlx_hook(info.mlx_win, 33, 1L << 5, exit_game, &info);
	mlx_loop_hook(info.mlx, draw_map, &info);
	mlx_loop(info.mlx);
}
