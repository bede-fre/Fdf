/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/14 15:41:20 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_print_list(t_stock *list)
{
	t_stock	*line;
	char	*nbr;

	while (list)
	{
		line = list;
		while (line)
		{
			ft_putnbr(line->z);
			if (line->color)
			{
				ft_putstr(",0x");
				 nbr = ft_itoa_base(line->color, 16);
				ft_putstr(nbr);
				ft_memdel((void*)&nbr);
			}
			if (line->n_x != NULL)
				ft_putchar(' ');
			line = line->n_x;
		}
		ft_putchar('\n');
		list = list->n_y;
	}
}
/*
static void	ft_revdisplay(t_stock *list)
{
	t_stock	*line;
	char	*nbr;

	while (list)
	{
		line = list;
		while (line)
		{
			ft_putnbr(line->z);
			if (line->color)
			{
				ft_putstr(",0x");
				 nbr = ft_itoa_base(line->color, 16);
				ft_putstr(nbr);
				ft_memdel((void*)&nbr);
			}
			if (line->p_x != NULL)
				ft_putchar(' ');
			line = line->p_x;
		}
		ft_putchar('\n');
		list = list->p_y;
	}
}*/

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	t_values	*data;
	char	*line;

	i = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		data = ft_read_stock(fd, &line);
		ft_print_list(data->first_link);
		//ft_revdisplay(data->tp_x);
		//ft_color_range(data);
		close(fd);
		ft_free_lst(&data->first_link);
		free(data);
		free(line);
	}
	else
		ft_putendl_fd("usage : ./fdf [filename.fdf]", 2);
	return (0);
}
