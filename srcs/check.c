#include "../includes/so_long.h"

int	is_wall(const char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '1')
			return (0);
	return (1);
}

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\n\tinvalid number of argument\n", 34);
		exit(1);
	}
	if ((ft_strlen(argv[1]) < 4) || !ft_strchr(argv[1], '.')
			|| ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 5))
	{
		write(2, "Error\n\tSecond argumant must be *.ber\n", 37);
		exit(1);
	}
}

void	check_map(t_info info)
{
	int		i;
	char	c;

	i = -1;
	while (info.map[++i])
	{
		c = info.map[i];
		if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		{
			free(info.map);
			info.map = NULL;
			write(2, "Error\n\tmap must be composed of 0, 1, C, E or P\n", 47);
			exit(1);
		}
	}
	if (!ft_strchr(info.map, 'C') || !ft_strchr(info.map, 'E') \
			|| !ft_strchr(info.map, 'P'))
	{
		free(info.map);
		info.map = NULL;
		write(2, "Error\n\tmap must contain at least 1 exit,\
				1 collectible, and 1 starting position\n", 80);
		exit(1);
	}
	if (ft_strchr(info.map, 'P') != ft_strrchr(info.map, 'P'))
	{
		free(info.map);
		info.map = NULL;
		write(2, "Error\n\tthere must be only one player\n", 37);
		exit(1);
	}
}
