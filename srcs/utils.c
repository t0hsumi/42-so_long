#include "../includes/so_long.h"

void	map_to_pos(int index, size_t col_size, int *x, int *y)
{
	*x = index % col_size;
	*y = index / col_size;
}
