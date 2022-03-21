#include "../includes/so_long.h"

void	exit_game(t_info *info)
{
	(void)info;
	exit(0);
}

int	press_x(t_info *info)
{
	free(info->map);
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
	if (next_pos == '0')
	{
		info->x = next_x;
		info->y = next_y;
		printf("%d\n", ++(info->move_count));
	}
	else if (next_pos == 'C' || next_pos == 'P')
	{
		info->x = next_x;
		info->y = next_y;
		info->map[info->col_size * next_y + next_x] = '0';
		printf("%d\n", ++(info->move_count));
	}
	else if (next_pos == 'E')
	{
		printf("%d\n", ++(info->move_count));
		clear_game(info);
	}
	draw_map(info);
}
