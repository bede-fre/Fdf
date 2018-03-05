/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:58:42 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/05 16:30:22 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_free_lst(t_stock **list)
{
	t_stock	*lst;
	t_stock	*line;
	t_stock	*tp;

	line = *list;
	while (line)
	{
		lst = line;
		line = line->n_y;
		while (lst)
		{
			tp = lst;
			lst = lst->n_x;
			ft_memdel((void **)&tp);
		}
	}
}

void	ft_stock_x_max(t_values *val)
{
	static int	first;

	if (first++ == 0)
		val->x_max = val->ln;
}

void	ft_quit_line_less(t_values *val)
{
	if (val->ln < val->x_max)
	{
		if (val->x_max > val->ln)
		{
			ft_free_lst(&val->first_link);
			exit(1);
		}
	}
}

void	ft_quit_line_more(t_values *val)
{
	if (val->x_max != 0)
	{
		if (val->ln >= val->x_max)
		{
			ft_free_lst(&val->first_link);
			exit(1);
		}
	}
}

void	ft_proj_iso(t_stock *lst, t_stock *st, t_values *val)
{
	double ang;
	double x;
	double y;
	double z;

	lst->x -= (val->x_max) / 2;
	lst->y -= (val->y_max) / 2;

	x = (double)lst->x * cos(val->draw.r) - (double)lst->y * sin(val->draw.r);
	y = (double)lst->x * sin(val->draw.r) + (double)lst->y * cos(val->draw.r);
	z = (double)lst->z;

	ang = 30.0 * (M_PI / 180.0);

	lst->a = (int)(((x * cos(ang))
		+ (y * cos(ang + (120.0 * (M_PI / 180.0))))
		+ (z * cos(ang - (120.0 * (M_PI / 180.0)))))
		* val->draw.zoom);
	lst->a += val->draw.var_x;
	lst->b = (int)(((x * sin(ang))
		+ (y * sin(ang + (120.0 * (M_PI / 180.0))))
		+ (z * sin(ang - (120.0 * (M_PI / 180.0)))))
		* val->draw.zoom);
	lst->b += val->draw.var_y;
/*
	lst->a = (int)((((double)lst->x * cos(ang))
		+ ((double)lst->y * cos(ang + (120.0 * (M_PI / 180.0))))
		+ ((double)lst->z * cos(ang - (120.0 * (M_PI / 180.0)))))
		* val->draw.rzoom);
	lst->a += val->draw.rvar_x;
	lst->b = (int)((((double)lst->x * sin(ang))
		+ ((double)lst->y * sin(ang + (120.0 * (M_PI / 180.0))))
		+ ((double)lst->z * sin(ang - (120.0 * (M_PI / 180.0)))))
		* val->draw.rzoom);
	lst->b += val->draw.rvar_y;
*/
	lst->x += (val->x_max) / 2;
	lst->y += (val->y_max) / 2;

	st->x -= (val->x_max) / 2;
	st->y -= (val->y_max) / 2;
	x = (double)st->x * cos(val->draw.r) - (double)st->y * sin(val->draw.r);
	y = (double)st->x * sin(val->draw.r) + (double)st->y * cos(val->draw.r);
	z = (double)st->z;

	st->a = (int)(((x * cos(ang))
		+ (y * cos(ang + (120.0 * (M_PI / 180.0))))
		+ (z * cos(ang - (120.0 * (M_PI / 180.0)))))
		* val->draw.zoom);
	st->a += val->draw.var_x;
	st->b = (int)(((x * sin(ang))
		+ (y * sin(ang + (120.0 * (M_PI / 180.0))))
		+ (z * sin(ang - (120.0 * (M_PI / 180.0)))))
		* val->draw.zoom);
	st->b += val->draw.var_y;
/*
	st->a = (int)((((double)st->x * cos(ang))
		+ ((double)st->y * cos(ang + (120.0 * (M_PI / 180.0))))
		+ ((double)st->z * cos(ang - (120.0 * (M_PI / 180.0)))))
		* val->draw.rzoom);
	st->a += val->draw.rvar_x;
	st->b = (int)((((double)st->x * sin(ang))
		+ ((double)st->y * sin(ang + (120.0 * (M_PI / 180.0))))
		+ ((double)st->z * sin(ang - (120.0 * (M_PI / 180.0)))))
		* val->draw.rzoom);
	st->b += val->draw.rvar_y;
*/
	st->x += (val->x_max) / 2;
	st->y += (val->y_max) / 2;
}
