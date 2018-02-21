/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:28:36 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/21 14:47:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_algo(t_values *data, t_stock *lst, t_stock *st, int color)
{
	int	dx;
	int	dy;
	int	e;
	int	a1;
	int	a2;
	int	b1;
	int	b2;

	a1 = (lst->a) * (double)(data->zoom) + ((data->w_win)/2);
	a2 = (st->a) * (double)(data->zoom) + ((data->w_win)/2);
	b1 = (lst->b) * (double)(data->zoom)  + ((data->l_win)/2);
	b2 = (st->b) * (double)(data->zoom)  + ((data->l_win)/2);
	if ((dx = (a2 - a1)) != 0)
	{
		if (dx > 0)
		{
			if ((dy = (b2 - b1)) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx *= 2;
						dy = (dy * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, color); // nb_px = dy
							if ((a1 = (a1 + 1)) == a2)
								break;
							if ((e = (e - dy)) < 0)
							{
								b1 = (b1 + 1);
								e = (e + dx);
							}
						}
					}
					else
					{
						e = dy;
						dy *= 2;
						dx = (dx * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, color); //nb_px = dx
							if ((b1 = (b1 + 1)) == b2)
								break;
							if ((e = (e - dx)) < 0)
							{
								a1 = (a1 + 1);
								e = (e + dy);
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = dx;
						dx *= 2;
						dy = (dy * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, color); // nb_px = dy
							if ((a1 = (a1 + 1)) == a2)
								break;
							if ((e = (e + dy)) < 0)
							{
								b1 = (b1 - 1);
								e = (e + dx);
							}
						}
					}
					else
					{
						e = dy;
						dy *= 2;
						dx = (dx * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, color); // nb_px = dx
							if ((b1 = (b1 - 1)) == b2)
								break;
							if ((e = (e + dx)) > 0)
							{
								a1 = (a1 + 1);
								e = (e + dy);
							}
						}
					}
				}
			}
			else
			{
				while (a1 < a2)
					ft_fill_px(data, a1++, b1, color); // nb_px = dx
			}
		}
		else
		{
			if ((dy = (b2 - b1)) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx *= 2;
						dy = (dy * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, color); // nb_px = dy
							if ((a1 = (a1 - 1)) == a2)
								break;
							if ((e = (e + dy)) >= 0)
							{
								b1 = (b1 + 1);
								e = (e + dx);
							}
						}
					}
					else
					{
						e = dy;
						dy *= 2;
						dx = (dx * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, color); // nb_px = dx
							if ((b1 = (b1 + 1)) == b2)
								break;
							if ((e = (e + dx)) <= 0)
							{
								a1 = (a1 - 1);
								e = (e + dy);
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx *= 2;
						dy = (dy * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, color); // nb_px = dy
							if ((a1 = (a1 - 1)) == a2)
								break;
							if ((e = (e - dy)) >= 0)
							{
								b1 = (b1 - 1);
								e = (e + dx);
							}
						}
					}
					else
					{
						e = dy;
						dy *= 2;
						dx = (dx * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, color); // nb_px = dx
							if ((b1 = (b1 - 1)) == b2)
								break;
							if ((e = (e - dx)) >= 0)
							{
								a1 = (a1 - 1);
								e = (e + dy);
							}
						}
					}
				}
			}
			else
			{
				while (a1 > a2)
					ft_fill_px(data, a1--, b1, color); // nb_px = dx
			}
		}
	}
	else
	{
		if ((dy = (b2 - b1)) != 0)
		{
			if (dy > 0)
			{
				while (b1 < b2)
					ft_fill_px(data, a1, b1++, color); // nb_px = dy
			}
			else
			{
				while (b1 > b2)
					ft_fill_px(data, a1, b1--, color); // nb_px = dy
			}
		}
	}
	ft_fill_px(data, a2, b2, color);
}
