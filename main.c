#include "ft_fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY) == -1))
			return (-1);
		ft_stock_check(fd, &line);
		if (close(fd) == -1)
			return (-1);
	}
	else
		ft_putendl_fd("usage : ./fdf [filename.fdf]", 2);
	return (0);
}
