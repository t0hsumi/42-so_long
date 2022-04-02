#include "../includes/so_long.h"

void	clear_game(t_info *info)
{
	int	i;

	ft_putnbr_fd(++(info->move_count), 1);
	write(1, "\n", 1);
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
