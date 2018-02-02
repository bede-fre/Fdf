/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:11:28 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/02 17:24:44 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_fdf.h"

/*
static void		ft_clear_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		ft_memdel((void*)tab[i]);
	ft_memdel((void*)tab);
}*/

static void		ft_lst_link(t_stock *data, t_stock *tp_x, t_stock *tp_y)
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
	char	**tab;
	char	**tp;

	tab = ft_split_whitespaces(*line);
	while (tab[++(val->ln)])
	{
		if (tab[(val->ln) + 1] != NULL)
			if (!(data->n_x = (t_stock*)ft_memalloc(sizeof(t_stock))))
				//PUT MALLOC PROTECTION DUMMY !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		data->x = val->ln;
		data->y = val->cl;
		tp = ft_strsplit(tab[val->ln], ',');
		data->z = ft_atoi(tp[0]);
		data->color = (tp[1]) ? ft_atoi_base(tp[1], 16) : WHITE_COLOR;
		ft_lst_link(data, val->tp_x, val->tp_y);
		val->tp_x = data;
		if (data->y != 0)
			val->tp_y = val->tp_y->n_x;
		data = data->n_x;
		}
//	ft_clear_tab(tp);
//	ft_clear_tab(tab);
}


static void		ft_links_creation(t_values *val, t_stock *data)
{
	static int		first;

	first = 0;
	if (first++ == 0)
	{
		if (!(data = (t_stock*)ft_memalloc(sizeof(t_stock))))
			//PUT MALLOC PROTECTION DUMMY !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		val->first_x = data;
		val->first_link = data;
	}
	else
	{
		if (!(data->n_y = (t_stock*)ft_memalloc(sizeof(t_stock))))
			//PUT MALLOC PROTECTION DUMMY !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		data = data->n_y;
		val->first_x = data;
	}
}

t_stock	*ft_read_stock(int fd, char **line)
{
	//int			first;
	t_stock		*data;
	t_values	*val;

//	first = 0;
	data = NULL;
	val = NULL;
	if (!(val = (t_values*)ft_memalloc(sizeof(t_values))))
		return (NULL);
	while (ft_gnl(fd, line) == 1)
	{
		val->ln = -1;
		/*if (first++ == 0)
		{
			if (!(data = (t_stock*)ft_memalloc(sizeof(t_stock))))
					return (NULL);
				val->first_x = data;
				val->first_link = data;
		}
		else
		{
			if (!(data->n_y = (t_stock*)ft_memalloc(sizeof(t_stock))))
				return (NULL);
			data = data->n_y;
			val->first_x = data;
		}*/
		ft_links_creation(val, data);
		ft_stock(val, data, line);
		(val->cl)++;
		val->tp_y = val->first_x;
		data = val->first_x;
	}
	val->x_max = val->ln;
	val->y_max = val->cl;
	ft_putnbr(val->y_max);
	return (data);
}
