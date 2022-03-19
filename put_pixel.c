#include <mlx.h>

int main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 500, "Hello World!");
	mlx_pixel_put(mlx, mlx_win, 20, 30, 0x00FF0000);
	mlx_loop(mlx);
}
