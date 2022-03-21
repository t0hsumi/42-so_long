#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../includes/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <malloc.h>
# include <stdio.h>

typedef struct s_info
{
	void	*mlx;
	void	*mlx_win;
	void	*ground;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
	char	*map;
	size_t	col_size;
	int		x;
	int		y;
}				t_info;

void	check_arg(int argc, char **argv);
int	xopen(const char *pathname, int flags);
int	xget_next_line(int fd, char **line);

#endif
