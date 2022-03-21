#include "../includes/so_long.h"

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\n\tinvalid number of argument", 33);
		exit(1);
	}
	if ((ft_strlen(argv[1]) < 4) || !ft_strchr(argv[1], '.') ||
		ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 5))
	{
		write(2, "Error\n\tSecond argumant must be *.ber", 36);
		exit(1);
	}
}

