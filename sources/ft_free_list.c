/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:58:42 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/20 17:06:32 by bede-fre         ###   ########.fr       */
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

void	ft_proj_iso(t_stock*data, t_values *val)
{
	double		ang;

	val->w_win = 1600;
	val->l_win = 1200;
	val->zoom = 40;
	ang = 30.0  * (M_PI/180.0);
	data->a = ((data->x * cos(ang))
		+ (data->y * cos(ang + (120.0 * (M_PI/180.0))))
		+ (data->z * cos(ang - (120.0 * (M_PI/180.0)))));
	data->b = ((data->x * sin(ang))
		+ (data->y * sin(ang + (120.0 * (M_PI/180.0))))
		+ (data->z * sin(ang - (120.0 * (M_PI/180.0)))));
}
