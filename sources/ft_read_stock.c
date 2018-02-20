/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:11:28 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/20 13:53:35 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void		ft_clear_tab(char **tab)
{
	int			i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static void		ft_link(t_stock *data, t_stock *tp_x, t_stock *tp_y)
{
	if (data->y == 0 && data->x != 0)
	{
		data->p_x = tp_x;
		tp_x->n_x = data;
	}
	else if (data->x == 0 && data->y != 0)
	{
		data->p_y = tp_y;
		tp_y->n_y = data;
	}
	else if (data->x != 0 && data->y != 0)
	{
		data->p_x = tp_x;
		data->p_y = tp_y;
		tp_x->n_x = data;
		tp_y->n_y = data;
	}
}

static void		ft_stock(t_values *val, t_stock *data, char **line)
{
	char		**tab;
	char		**tp;

	tab = ft_split_whitespaces(*line);
	while (tab[++(val->ln)])
	{
		if (tab[(val->ln) + 1] != NULL)
			if (!(data->n_x = (t_stock*)ft_memalloc(sizeof(t_stock))))
				ft_free_lst(&val->first_link);
		data->x = val->ln;
		data->y = val->cl;
		tp = ft_strsplit(tab[val->ln], ',');
		data->z = ft_atoi(tp[0]);
		data->color = (tp[1]) ? ft_atoi_base(tp[1], 16) : WHITE_COLOR;
		ft_proj_iso(data, val);
		ft_quit_line_more(val);
		ft_link(data, val->tp_x, val->tp_y);
		val->tp_x = data;
		if (data->y != 0)
			val->tp_y = val->tp_y->n_x;
		data = data->n_x;
		ft_clear_tab(tp);
	}
	ft_quit_line_less(val);
	ft_clear_tab(tab);
}

static t_stock	*ft_links_creation(t_values *val, t_stock *data)
{
	if (!(data->n_y = (t_stock*)ft_memalloc(sizeof(t_stock))))
		ft_free_lst(&val->first_link);
	data = data->n_y;
	val->first_x = data;
	return (data);
}

t_values		*ft_read_stock(int fd, char **line)
{
	t_stock		*data;
	t_values	*val;
	static int	first;

	if (!(data = (t_stock*)ft_memalloc(sizeof(t_stock)))
		|| !(val = (t_values*)ft_memalloc(sizeof(t_values))))
		return (NULL);
	val->first_x = data;
	val->first_link = data;
	while (ft_gnl(fd, line) == 1)
	{
		val->ln = -1;
		if (first == 0)
			first++;
		else
			data = ft_links_creation(val, data);
		ft_stock(val, data, line);
		(val->cl)++;
		val->tp_y = val->first_x;
		data = val->first_x;
		free(*line);
		ft_stock_x_max(val);
	}
	val->y_max = val->cl;
	return (val);
}
