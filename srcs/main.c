#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_info	info;

	check_arg(argc, argv);
	read_map(&info, argv[1]);
	check_map(info);
	init_str(&info);
	mlx_hook(info.mlx_win, 02, 1L << 0, key_press, &info);
	mlx_hook(info.mlx_win, 33, 1L << 5, exit_game, &info);
	mlx_loop_hook(info.mlx, draw_map, &info);
	mlx_loop(info.mlx);
}
