#include "../includes/so_long.h"

void	map_to_pos(int index, size_t col_size, int *x, int *y)
{
	*x = index % col_size;
	*y = index / col_size;
}

void	count_collectible(t_info *info)
{
	int	i;

	i = 0;
	info->collectible_num = 0;
	while (info->map[i])
		if (info->map[i] == 'C')
			info->collectible_num++;
}
