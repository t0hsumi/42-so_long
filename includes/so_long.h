#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../includes/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_info
{
	void	*mlx;
	void	*mlx_win;
	void	*image[5];
	char	*map;
	size_t	col_size;
	size_t	row_size;
	int		x;
	int		y;
	int		move_count;
}				t_info;

enum
{
	EMPTY,
	WALL,
	PLAYER,
	EXIT,
	COLLECTIBLE
};

# define A 97
# define S 115
# define D 100
# define W 119
# define ESC 65307

void	map_to_pos(int index, size_t col_size, int *x, int *y);

void	check_arg(int argc, char **argv);
void	check_map(t_info info);
int		is_wall(const char *line);

int		xopen(const char *pathname, int flags);
int		xget_next_line(int fd, char **line);
char	*xft_strdup(const char *s1);
char	*xft_strjoin(char const *s1, char const *s2);
int		xclose(int fd);
void	*xmlx_init(void);
void	*xmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*xmlx_xpm_file_to_image(void *mlx_ptr, char *filename, \
		int *width, int *height);

#endif
