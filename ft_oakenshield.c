/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oakenshield.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:11:28 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/01 17:50:01 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_fdf.h"

static void		ft_lst_link(t_stock *data, t_stock *tp_x, t_stock *tp_y)
{
	if (data->y == 0 && data->x != 0)
	{
		data->p_x = tp_x;
		tp_x->n_x = data;
	}
	else if (data->x == 0 && data->y != 0)
	{
		data->p_y = tp_y;
		tp_y->n_y = data;
	}
	else if (data->x != 0 && data->y != 0)
	{
		data->p_x = tp_x;
		data->p_y = tp_y;
		tp_x->n_x = data;
		tp_y->n_y = data;
	}
}

t_stock	*ft_stock_check(int fd, char **line)
{
	int			g;
	int			ln;
	int			cl;
	char		**tab;
	char		**tmp;
	t_stock		*first_x;
	t_stock		*data;
	t_stock		*tp_x;
	t_stock		*tp_y;
	t_stock		*current;
	t_values	*values;

	g = 0;
	cl = 0;
	first_x = NULL;
	tp_x = NULL;
	tp_y = NULL;
	values = NULL;
	while (ft_gnl(fd, line) == 1)
	{
		ln = -1;
		tab = ft_split_whitespaces(*line);
		if (g++ == 0)
		{
			if (!(data = (t_stock*)ft_memalloc(sizeof(t_stock))))
					return (NULL);
				first_x = data;
				current = data;
		}
		else
		{
			if (!(data->n_y = (t_stock*)ft_memalloc(sizeof(t_stock))))
				return (NULL);
			data = data->n_y;
			first_x = data;
		}
		while (tab[++ln])
		{
			if (tab[ln + 1] != NULL)
			{
				if (!(data->n_x = (t_stock*)ft_memalloc(sizeof(t_stock))))
					return (NULL);
			}
			data->x = ln;
			data->y = cl;
			tmp = ft_strsplit(tab[ln], ',');
			data->z = ft_atoi(tmp[0]);
			data->color = (tmp[1]) ? ft_atoi_base(tmp[1], 16) : WHITE_COLOR;
			ft_lst_link(data, tp_x, tp_y);
			tp_x = data;
			if (data->y != 0)
				tp_y = tp_y->n_x;
			data = data->n_x;
		}
		cl++;
		tp_y = first_x;
		data = first_x;
	}
	if (!(values = (t_values*)ft_memalloc(sizeof(t_values))))
		return (NULL);
	values->x_max = ln;
	values->y_max = cl;
	ft_putstr("x_max = ");
	ft_putnbr(values->x_max);
	ft_putchar('\n');
	ft_putstr("y_max = ");
	ft_putnbr(values->y_max);

	return (data);
}

/*
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
*/
