#include "../includes/so_long.h"

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
