/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_error_iso_proj.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:58:42 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/07 09:41:35 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_free_lst(t_stock **list, char error)
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
	if (error != 0)
		ft_error("Program failed");
}

void		ft_quit_line_more(t_values *val)
{
	if (val->x_max != 0)
		if (val->ln >= val->x_max)
			ft_free_lst(&val->first_link, 1);
}

void		ft_quit_line_less(t_values *val)
{
	if (val->ln < val->x_max)
		if (val->x_max > val->ln)
			ft_free_lst(&val->first_link, 1);
}

static void	ft_iso_link(t_values *val, t_stock *lst)
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
	lst->x += (val->x_max) / 2;
	lst->y += (val->y_max) / 2;
}

void		ft_proj_iso(t_stock *lst, t_stock *st, t_values *val)
{
	ft_iso_link(val, lst);
	ft_iso_link(val, st);
}
