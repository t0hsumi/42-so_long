#include "../includes/so_long.h"

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
