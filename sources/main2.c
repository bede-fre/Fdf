/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/20 13:30:06 by bede-fre         ###   ########.fr       */
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

int		ft_deal_key(int key, t_values *data)
{
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
	(void)data;
	if (key == 4)
	{
		exit(0);
	}
	return (0);
}

void	ft_fill_px(t_values *data, int x, int y, int color)
{
	int		first;

	first = (x * (data->bpp) / 8) + (y * data->sz_ln_px);
	
	if (first < 0 || x > 500 || y > 500)
	{
		return ;
	}
	data->s_px[first] = (unsigned char)(color);
	data->s_px[first + 1] = (unsigned char)(color >> 8);
	data->s_px[first + 2] = (unsigned char)(color >> 16);
	data->s_px[first + 3] = (unsigned char)(color >> 24);
}

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
}

int	main(int ac, char **av)
{
	int			fd;
	t_values	*data;
	char		*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		data = ft_read_stock(fd, &line);
		close(fd);
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx,500,500, "FdF");
		data->img = mlx_new_image(data->mlx, 500, 500);
		data->s_px = mlx_get_data_addr(data->img, &data->bpp, &data->sz_ln_px, &data->endian);
		/*while (++y < 500)
		{
			x = -1;
			while (++x < 500)
				ft_fill_px(data, x, y, 0x82E0AA);
		}
		//mlx_clear_window(data->mlx, data->win);
		//mlx_destroy_image(data->mlx, data->img);
*/
		ft_display_lst(data, data->first_link);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_mouse_hook(data->win, ft_deal_keymouse, data);
		mlx_key_hook(data->win, ft_deal_key, data);
		//mlx_hook(data->win, 17, (1L<<17), &ft_close_win, data);
		mlx_loop(data->mlx);
		ft_free_lst(&data->first_link);
		free(data);
		free(line);
	}
	else
		ft_putendl_fd("usage : ./fdf [filename.fdf]", 2);
	return (0);
}
