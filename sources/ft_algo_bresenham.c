/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:28:36 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/05 17:43:24 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

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
	ft_gradient_color(val, lst, st);
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
