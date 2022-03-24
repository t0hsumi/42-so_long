#include "../includes/so_long.h"

int	exit_game(t_info *info)
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
	exit(1);
}

int	img_change(int keycode, t_info *info)
{
	if (keycode == A || keycode == S || keycode == D || keycode == W)
		player_move(keycode, info);
	else if (keycode == ESC)
		exit_game(info);
	return (0);
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
			clear_game(info);
		}
		info->map[info->col_size * info->y + info->x] = 'P';
	}
	if (next_pos == 'E' || next_pos == '0' || next_pos == 'C')
		write(1, "\n", 1);
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
	draw_map(info);
}
