/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/22 14:39:12 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
/*
int		ft_close_win(int key, t_values *data)
{
	(void)key;
	(void)data;
	ft_free_lst(&data->first_link);
	exit(0);
	return (0);
}*/

void	ft_display_lst(t_values *data, t_stock *list)
{
	t_stock	*line;
	t_stock *col;

	col = list;
	while (col)
	{
		line = col;
		while (line)
		{
			if (line->n_x)
				ft_algo(data, line, line->n_x, line->color);
			if (line->n_y)
				ft_algo(data, line, line->n_y, line->color);
			line = line->n_x;
		}
		col = col->n_y;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int		ft_deal_key(int key, t_values *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->w_win, data->l_win);
	data->s_px = mlx_get_data_addr(data->img, &data->bpp, &data->sz_ln_px, &data->endian);
	if (key == 69)
		data->zoom += 5;
	if (key == 78)
		data->zoom -= 5;
	if (key == 123)
		data->var_x -= 10;
	if (key == 124)
		data->var_x += 10;
	if (key == 125)
		data->var_y += 10;
	if (key == 126)
		data->var_y -= 10;
	ft_display_lst(data, data->first_link);
	if (key == 53)
	{
		ft_free_lst(&data->first_link);
		exit(0);
	}
	return (0);
}

int		ft_deal_keymouse(int key, int x, int y, t_values *data)
{
	(void)x;
	(void)y;
	(void)key;
	(void)data;
	return (0);
}

void	ft_fill_px(t_values *data, int x, int y, int color)
{
	int		first;

	first = (x * (data->bpp) / 8) + (y * data->sz_ln_px);
	
	if (first < 0 || x >= (data->w_win) || y >= (data->l_win) ||
		x < 0 || y < 0)
		return ;
	data->s_px[first] = (unsigned char)(color);
	data->s_px[first + 1] = (unsigned char)(color >> 8);
	data->s_px[first + 2] = (unsigned char)(color >> 16);
	data->s_px[first + 3] = (unsigned char)(color >> 24);
}

int	main(int ac, char **av)
{
	int			fd;
	t_values	*data;
	char		*line;

	if (ac == 4)
	{

		fd = open(av[1], O_RDONLY);
		data = ft_read_stock(fd, &line);
		close(fd);
		data->w_win = 1600;
		data->l_win = 1200;
		
		data->var_x = (int)((data->w_win) / 2.0);
		data->var_y = (int)((data->l_win) / 2.0);
		data->zoom = 20;

		if (!(data->color = (t_color*)ft_memalloc(sizeof(t_color))))
			exit(1);
		
		ft_color_range(data);
		
		ft_compare_color(ft_atoi_base(av[2], 16), ft_atoi_base(av[3], 16), data);
		//ft_gradient_color(data, data->first_link, data->first_link->n_x);
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, data->w_win, data->l_win, "FdF");
		data->img = mlx_new_image(data->mlx, data->w_win, data->l_win);
		data->s_px = mlx_get_data_addr(data->img, &data->bpp, &data->sz_ln_px, &data->endian);
		ft_display_lst(data, data->first_link);
		//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_mouse_hook(data->win, ft_deal_keymouse, data);
		mlx_key_hook(data->win, ft_deal_key, data);
		//mlx_hook(data->win, 17, (1L<<17), &ft_close_win, data);
		mlx_loop(data->mlx);
		ft_free_lst(&data->first_link);
		free(data);
		free(line);
	}
	else
		ft_putendl_fd("usage : ./fdf [filename.fdf] color_bottom [0x******] color_top [0x******]" , 2);
	return (0);
}
