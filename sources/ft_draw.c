/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:42:53 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/06 16:20:09 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_display(t_values *val, t_stock *list)
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

static void	ft_rev_display(t_values *val, t_stock *list)
{
	t_stock	*line;
	t_stock	*col;

	col = list;
	while (col)
	{
		line = col;
		while (line)
		{
			if (line->p_x)
				ft_algo(val, line, line->p_x, line->color);
			if (line->p_y)
				ft_algo(val, line, line->p_y, line->color);
			line = line->p_x;
		}
		col = col->p_y;
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
}

static void	ft_move_zoom(int key, t_values *val)
{
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
}

static void	ft_rotate(int key, t_values *val)
{
	if (key == 0)
	{
		if (val->draw.r > 0.0 * (M_PI / 180.0))
			val->draw.r -= 10.0 * (M_PI / 180.0);
		else
			val->draw.r = 350.0 * (M_PI / 180.0);
	}
	if (key == 2)
	{
		if (val->draw.r < 350.0 * (M_PI / 180.0))
			val->draw.r += 10.0 * (M_PI / 180.0);
		else
			val->draw.r = 0.0 * (M_PI / 180.0);
	}
}

int			ft_deal_key(int key, t_values *val)
{
	mlx_clear_window(val->draw.mlx, val->draw.win);
	mlx_destroy_image(val->draw.mlx, val->draw.img);
	val->draw.img = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px = mlx_get_data_addr(val->draw.img, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	if (key == 69 || key == 78 || key == 123 || key == 124 || key == 125
		|| key == 126)
		ft_move_zoom(key, val);
	if (key == 0 || key == 2)
		ft_rotate(key, val);
	if ((val->draw.r > 46.0 * (M_PI / 180.0))
		&& (val->draw.r < 225.0 * (M_PI / 180.00)))
		ft_rev_display(val, val->last_link);
	else
		ft_display(val, val->first_link);
	if (key == 53)
	{
		ft_free_lst(&val->first_link);
		exit(0);
	}
	return (0);
}
