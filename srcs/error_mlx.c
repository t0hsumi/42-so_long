#include "../includes/so_long.h"

void	*xmlx_init(void)
{
	void	*res;

	res = mlx_init();
	if (!res)
	{
		perror("mlx_init");
		exit(1);
	}
	return (res);
}

void	*xmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	void	*res;

	res = mlx_new_window(mlx_ptr, size_x, size_y, title);
	if (!res)
	{
		perror("mlx_new_window");
		exit(1);
	}
	return (res);
}

void	*xmlx_xpm_file_to_image(void *mlx_ptr, char *filename, \
		int *width, int *height)
{
	void	*res;

	res = mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
	if (!res)
	{
		perror("mlx_xpm_file_to_image");
		exit(1);
	}
	return (res);
}
