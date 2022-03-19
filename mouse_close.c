#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int press_x(int button, int x, int y, t_vars *param)
{
	printf("mlx = %p, win = %p\n", (*param).mlx, (*param).mlx);
	mlx_destroy_window(param->mlx, param->win);
	return 0;
}

int	main(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	(*vars).mlx = mlx_init();
	(*vars).win = mlx_new_window((*vars).mlx, 640, 480, "Hello world!");
	printf("vars = %p, mlx = %p, win = %p\n",vars, (*vars).mlx, (*vars).win);
	mlx_hook( (*vars).win, 33, 1L<<2, press_x, vars);
	mlx_loop( (*vars).mlx);
}
