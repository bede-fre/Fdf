/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:42:53 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/05 16:37:20 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_size_window(t_values *val, char *len, char *wid)
{
	val->draw.l_win = (double)(ft_atoi(len));
	val->draw.w_win = (double)(ft_atoi(wid));
	val->draw.var_x = (int)(val->draw.l_win / 2.0);
	val->draw.var_y = (int)(val->draw.w_win / 2.0);
	val->draw.zoom = 1.0;
	val->draw.r = 0.0 * (M_PI / 180.0);
}

void	ft_display(t_values *val, t_stock *list)
{
	t_stock	*line;
	t_stock	*col;

	col = list;
	while (col)
	{
		line = col;
		while (line)
		{
			if (line->n_x)
				ft_algo(val, line, line->n_x, line->color);
			if (line->n_y)
				ft_algo(val, line, line->n_y, line->color);
			line = line->n_x;
		}
		col = col->n_y;
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
}

int		ft_deal_key(int key, t_values *val)
{
	mlx_clear_window(val->draw.mlx, val->draw.win);
	mlx_destroy_image(val->draw.mlx, val->draw.img);
	val->draw.img = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px = mlx_get_data_addr(val->draw.img, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	if (key == 69)
		val->draw.zoom += 5;
	if (key == 78)
		val->draw.zoom -= 5;
	if (key == 123)
		val->draw.var_x -= 10;
	if (key == 124)
		val->draw.var_x += 10;
	if (key == 125)
		val->draw.var_y += 10;
	if (key == 126)
		val->draw.var_y -= 10;
	if (key == 0)
		val->draw.r -= 10.0 * (M_PI / 180.0);
	if (key == 2)
		val->draw.r += 10.0 * (M_PI / 180.0);
	ft_display(val, val->first_link);
	if (key == 53)
	{
		ft_free_lst(&val->first_link);
		exit(0);
	}
	return (0);
}

void	ft_fill_px(t_values *val, int x, int y, int color)
{
	int		first;

	first = (x * (val->draw.bpp) / 8) + (y * val->draw.sz_ln_px);
	if (first < 0 || x >= (val->draw.w_win) || y >= (val->draw.l_win) ||
		x < 0 || y < 0)
		return ;
	val->draw.s_px[first] = (unsigned char)(color);
	val->draw.s_px[first + 1] = (unsigned char)(color >> 8);
	val->draw.s_px[first + 2] = (unsigned char)(color >> 16);
	val->draw.s_px[first + 3] = (unsigned char)(color >> 24);
}
