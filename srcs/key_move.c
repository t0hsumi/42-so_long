#include "../includes/so_long.h"

int exit_game(t_info *info)
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

void	player_move(int keycode, t_info *info)
{
	int		next_x;
	int		next_y;
	char	next_pos;

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
	next_pos = info->map[info->col_size * next_y + next_x];
	if (next_pos != '1')
		info->map[info->col_size * info->y + info->x] = '0';
	if (next_pos == '0')
	{
		info->x = next_x;
		info->y = next_y;
		info->map[info->col_size * next_y + next_x] = 'P';
		printf("%d\n", ++(info->move_count));
	}
	else if (next_pos == 'C')
	{
		info->x = next_x;
		info->y = next_y;
		info->map[info->col_size * next_y + next_x] = 'P';
		printf("%d\n", ++(info->move_count));
	}
	else if (next_pos == 'E')
	{
		printf("%d\n", ++(info->move_count));
		clear_game(info);
	}
	draw_map(info);
}
