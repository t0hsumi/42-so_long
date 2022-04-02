#include "../includes/so_long.h"

int	key_press(int keycode, t_info *info)
{
	if (keycode == A || keycode == S || keycode == D || keycode == W)
		player_move(keycode, info);
	else if (keycode == ESC)
		exit_game(info);
	return (0);
}
