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

static void	modify_state(t_info *info, int next_x, int next_y)
{
	char	next_pos;

	next_pos = info->map[info->col_size * next_y + next_x];
	if (next_pos != '1')
		info->map[info->col_size * info->y + info->x] = '0';
	if (next_pos == '0')
	{
		info->x = next_x;
		info->y = next_y;
		info->map[info->col_size * next_y + next_x] = 'P';
		ft_putnbr_fd(++(info->move_count), 1);
	}
	if (next_pos == 'C')
	{
		info->x = next_x;
		info->y = next_y;
		info->collectible_num--;
		info->map[info->col_size * next_y + next_x] = 'P';
		ft_putnbr_fd(++(info->move_count), 1);
	}
	else if (next_pos == 'E')
	{
		if (info->collectible_num == 0)
		{
			ft_putnbr_fd(++(info->move_count), 1);
			write(1, "\n", 1);
			clear_game(info);
		}
		info->map[info->col_size * info->y + info->x] = 'P';
	}
	if (next_pos == '0' || next_pos == 'C')
		write(1, "\n\033[1F\033[1G", sizeof("\n\033[1F\033[1G") - 1);
}

void	player_move(int keycode, t_info *info)
{
	int		next_x;
	int		next_y;

	if (keycode == A)
	{
		next_y = info->y;
		next_x = info->x - 1;
	}
	else if (keycode == D)
	{
		next_y = info->y;
		next_x = info->x + 1;
	}
	else if (keycode == W)
	{
		next_x = info->x;
		next_y = info->y - 1;
	}
	else
	{
		next_x = info->x;
		next_y = info->y + 1;
	}
	modify_state(info, next_x, next_y);
}
