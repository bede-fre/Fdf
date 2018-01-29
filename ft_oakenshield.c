/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oakenshield.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:11:28 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/29 18:47:15 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_stock	*ft_stock_check(int fd, char **line)
{
	int		y;
	int		i;
	char	**tab;
	char	**tmp;
	t_stock *data;


	i = 0;
	while (ft_gnl(fd, line) == 1)
	{
		while (*line)
		{
			y = -1;
			tab = ft_split_whitespaces(*line);
			while (tab[++y])
			{
				tmp = ft_strsplit(tab[y], ',');
				ft_atoi(tmp[0]);
				if (tmp[1] != NULL)
					ft_atoi_base(tmp[1], 16);
			
			}
				ft_atoi(tab[y]);
				if (tab)
			}

		}
	
	
	}



}

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
