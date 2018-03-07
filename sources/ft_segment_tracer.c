/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segment_tracer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:28:36 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/07 10:02:37 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_fill_px(t_values *val, int x, int y, int color)
{
	int		px;

	px = (x * (val->draw.bpp) / 8) + (y * val->draw.sz_ln_px);
	if (px < 0 || x >= (val->draw.w_win) || y >= (val->draw.l_win) ||
		x < 0 || y < 0)
		return ;
	val->draw.s_px[px] = (unsigned char)(color);
	val->draw.s_px[px + 1] = (unsigned char)(color >> 8);
	val->draw.s_px[px + 2] = (unsigned char)(color >> 16);
	val->draw.s_px[px + 3] = (unsigned char)(color >> 24);
}

static void	ft_fill_line(t_values *val, int col)
{
	val->algo.cumul = val->algo.da / 2;
	while (val->algo.i <= val->algo.da)
	{
		val->algo.a += val->algo.cpta;
		val->algo.cumul += val->algo.db;
		if (val->algo.cumul >= val->algo.da)
		{
			val->algo.cumul -= val->algo.da;
			val->algo.b += val->algo.cptb;
		}
		ft_fill_px(val, val->algo.a, val->algo.b, (col != (int)(NULL)
			? col : ft_merge_color(val->col.l_s_r, val->col.l_s_g,
			val->col.l_s_b)));
		val->algo.i++;
	}
}

static void	ft_fill_column(t_values *val, int col)
{
	val->algo.cumul = val->algo.db / 2;
	while (val->algo.i <= val->algo.db)
	{
		val->algo.b += val->algo.cptb;
		val->algo.cumul += val->algo.da;
		if (val->algo.cumul >= val->algo.db)
		{
			val->algo.cumul -= val->algo.db;
			val->algo.a += val->algo.cpta;
		}
		ft_fill_px(val, val->algo.a, val->algo.b, (col != (int)(NULL)
			? col : ft_merge_color(val->col.l_s_r, val->col.l_s_g,
			val->col.l_s_b)));
		val->algo.i++;
	}
}

void		ft_algo(t_values *val, t_stock *lst, t_stock *st, int col)
{
	ft_gradient_col(val, lst, st);
	ft_proj_iso(lst, st, val);
	val->algo.a = lst->a;
	val->algo.b = lst->b;
	val->algo.da = st->a - val->algo.a;
	val->algo.db = st->b - val->algo.b;
	val->algo.cpta = (val->algo.da > 0) ? 1 : -1;
	val->algo.cptb = (val->algo.db > 0) ? 1 : -1;
	val->algo.da = ft_abs(val->algo.da);
	val->algo.db = ft_abs(val->algo.db);
	val->algo.i = 1;
	ft_fill_px(val, val->algo.a, val->algo.b, (col != (int)(NULL)
		? col : ft_merge_color(val->col.l_s_r, val->col.l_s_g,
		val->col.l_s_b)));
	if (val->algo.da > val->algo.db)
		ft_fill_line(val, col);
	else
		ft_fill_column(val, col);
}
