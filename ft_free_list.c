/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:58:42 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/13 17:32:46 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
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
	static	int	first;

	if (first++ == 0)
		val->x_max = val->ln;
}
