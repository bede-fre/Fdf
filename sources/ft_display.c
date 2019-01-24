/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:12:52 by bede-fre          #+#    #+#             */
/*   Updated: 2019/01/24 17:25:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_display(t_values *val, t_stock *list)
{
	t_stock	*line;
	t_stock	*col;

	val->first = 0;
	col = list;
	while (col)
	{
		line = col;
		while (line)
		{
			if (line->n_x)
				ft_algo(val, line, line->n_x, line->color);
			if (line->n_y)
			{
				if (val->first == 0)
					val->first = 1;
				else
					ft_algo(val, line, line->n_y, line->color);
			}
			line = line->n_x;
		}
		col = col->n_y;
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
}
