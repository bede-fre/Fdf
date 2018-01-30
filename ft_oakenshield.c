/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oakenshield.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:11:28 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/30 13:48:55 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"


void	ft_four_horsemen(t_stock *data, t_stock *tp_x, t_stock *tp_y)
{
	if (data->y == 0)
	{
		data->p_x = tp_x;
		tp_x->n_x = data;
	}
	else if (data->x == 0)
	{
		data->p_y = tp_y;
		tp_y->n_y = data;
	}
	else
	{
		data->p_x = tp_x;
		data->p_y = tp_y;
		tp_x->n_x = data;
		tp_y->n_y = data;
	}
}



t_stock	*ft_stock_check(int fd, char **line)
{
	int		cl;
	int		ln;
	char	**tab;
	char	**tmp;
	t_stock	*data;
	t_stock	*tp_x;
	t_stock	*tp_y;

	data = (t_stock*)malloc(sizeof(t_stock));
	ln = 0;
	tp_x = NULL;
	tp_y = NULL;
	while (ft_gnl(fd, line) == 1)
	{
		data->y = ln++;
		while (*line)
		{
			cl = -1;
			tab = ft_split_whitespaces(*line);
			while (tab[++cl])
			{
				data->x = cl;
				tmp = ft_strsplit(tab[cl], ',');
				data->z = ft_atoi(tmp[0]);
				if (tmp[1] != NULL)
					data->color = ft_atoi_base(tmp[1], 16);
				else
					data->color = 16777215;
				if ()
				while ( )
				{
					tp_x = data->n_x;
					tp_y = data->n_y;
				}

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
