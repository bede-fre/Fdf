/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:58:42 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/22 11:22:38 by bede-fre         ###   ########.fr       */
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

void	ft_proj_iso(t_stock *lst, t_stock *st, t_values *data)
{
	double		ang;

	ang = 30.0  * (M_PI/180.0);
	lst->a = (int)((((double)lst->x * cos(ang)) + ((double)lst->y * cos(ang + (120.0 * (M_PI/180.0))))
		+ ((double)lst->z * cos(ang - (120.0 * (M_PI/180.0))))) * (double)(data->zoom) + (double)(data->var_x));
	lst->b = (int)((((double)lst->x * sin(ang)) + ((double)lst->y * sin(ang + (120.0 * (M_PI/180.0))))
		+ ((double)lst->z * sin(ang - (120.0 * (M_PI/180.0))))) * (double)(data->zoom) + (double)(data->var_y));
	st->a = (int)((((double)st->x * cos(ang)) + ((double)st->y * cos(ang + (120.0 * (M_PI/180.0))))
		+ ((double)st->z * cos(ang - (120.0 * (M_PI/180.0))))) * (double)(data->zoom) + (double)(data->var_x));
	st->b = (int)((((double)st->x * sin(ang)) + ((double)st->y * sin(ang + (120.0 * (M_PI/180.0))))
		+ ((double)st->z * sin(ang - (120.0 * (M_PI/180.0))))) * (double)(data->zoom) + (double)(data->var_y));
}
