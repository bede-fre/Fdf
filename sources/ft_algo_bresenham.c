/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:28:36 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/19 17:59:34 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_algo(t_values *data, int a1, int b1, int a2, int b2)
{
	int	dx;
	int	dy;
	int	e;

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
							ft_fill_px(data, a1, b1, data->first_link->color);
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
							ft_fill_px(data, a1, b1, data->first_link->color);
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
							ft_fill_px(data, a1, b1, data->first_link->color);
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
							ft_fill_px(data, a1, b1, data->first_link->color);
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
					ft_fill_px(data, a1++, b1, data->first_link->color);
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
							ft_fill_px(data, a1, b1, data->first_link->color);
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
							ft_fill_px(data, a1, b1, data->first_link->color);
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
							ft_fill_px(data, a1, b1, data->first_link->color);
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
							ft_fill_px(data, a1, b1, data->first_link->color);
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
					ft_fill_px(data, a1--, b1, data->first_link->color);
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
					ft_fill_px(data, a1, b1++, data->first_link->color);
			}
			else
			{
				while (b1 > b2)
					ft_fill_px(data, a1, b1--, data->first_link->color);
			}
		}
	}
	ft_fill_px(data, a2, b2, data->first_link->color);
}

/*
void		draw_vertical_increasing(t_values *data, t_draw *val)
{
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->y1 = val->y1 + 1) == val->y2)
			break ;
	}
}

void		draw_vertical_decreasing(t_values *data, t_draw *val)
{
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->y1 = val->y1 - 1) == val->y2)
			break ;
	}
}

void		draw_octan_six(t_values *data, t_draw *val)
{
	val->e = val->dy;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->y1 = val->y1 - 1) == val->y2)
			break ;
		if ((val->e = val->e - val->dx) >= 0)
		{
			--val->x1;
			val->e += val->dy;
		}
	}
}

void		draw_octan_seven(t_values *data, t_draw *val)
{
	val->e = val->dy;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->y1 = val->y1 - 1) == val->y2)
			break ;
		if ((val->e = val->e + val->dx) > 0)
		{
			++val->x1;
			val->e += val->dy;
		}
	}
}

void		draw_octan_eight(t_values *data, t_draw *val)
{
	val->e = val->dx;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->x1 = val->x1 + 1) == val->x2)
			break ;
		if ((val->e = val->e + val->dy) < 0)
		{
			--val->y1;
			val->e += val->dx;
		}
	}
}

void		draw_horizontal_right(t_values *data, t_draw *val)
{
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->x1 = val->x1 + 1) == val->x2)
			break ;
	}
}

void		draw_horizontal_left(t_values *data, t_draw *val)
{
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->x1 = val->x1 - 1) == val->x2)
			break ;
	}
}

void		draw_octan_one(t_values *data, t_draw *val)
{
	val->e = val->dx;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->x1 = val->x1 + 1) == val->x2)
			break ;
		if ((val->e = val->e - val->dy) < 0)
		{
			++val->y1;
			val->e += val->dx;
		}
	}
}

void		draw_octan_two(t_values *data, t_draw *val)
{
	val->e = val->dy;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->y1 = val->y1 + 1) == val->y2)
			break ;
		if ((val->e = val->e - val->dx) < 0)
		{
			++val->x1;
			val->e += val->dy;
		}
	}
}

void		draw_octan_three(t_values *data, t_draw *val)
{
	val->e = val->dy;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->y1 = val->y1 + 1) == val->y2)
			break ;
		if ((val->e = val->e + val->dx) <= 0)
		{
			--val->x1;
			val->e += val->dy;
		}
	}
}

void		draw_octan_four(t_values *data, t_draw *val)
{
	val->e = val->dx;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->x1 = val->x1 - 1) == val->x2)
			break ;
		if ((val->e = val->e + val->dy) >= 0)
		{
			++val->y1;
			val->e += val->dx;
		}
	}
}

void		draw_octan_five(t_values *data, t_draw *val)
{
	val->e = val->dx;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		ft_fill_px(data, val->x1 - 200,
				val->y1 + 200, data->first_link->color);
		if ((val->x1 = val->x1 - 1) == val->x2)
			break ;
		if ((val->e = val->e - val->dy) >= 0)
		{
			--val->y1;
			val->e += val->dx;
		}
	}
}

static void		ft_dx_positive(t_values *data, t_draw *val)
{
	if (val->dy > 0)
	{
		if (val->dx >= val->dy)
			draw_octan_one(data, val);
		else
			draw_octan_two(data, val);
	}
	else if (val->dy < 0)
	{
		if (val->dx >= (-val->dy))
			draw_octan_eight(data, val);
		else
			draw_octan_seven(data, val);
	}
	else
		draw_horizontal_right(data, val);
}

static void		ft_dx_negative(t_values *data, t_draw *val)
{
	if (val->dy > 0)
	{
		if ((-val->dx) >= val->dy)
			draw_octan_four(data, val);
		else
			draw_octan_three(data, val);
	}
	else if (val->dy < 0)
	{
		if (val->dx <= val->dy)
			draw_octan_five(data, val);
		else
			draw_octan_six(data, val);
	}
	else
		draw_horizontal_left(data, val);
}

void			ft_algo(t_values *data, int a1, int a2, int b1, int b2)
{
	t_draw	val;

	val.x1 = a1;
	val.y1 = b1;
	val.x2 = a2;
	val.y2 = b2;
	val.dx = a2 - a1;
	val.dy = b2 - b1;

	if (val.dx > 0)
		ft_dx_positive(data, &val);
	else if (val.dx < 0)
		ft_dx_negative(data, &val);
	else
	{
		if (val.dy > 0)
			draw_vertical_increasing(data, &val);
		else if (val.dy < 0)
			draw_vertical_decreasing(data, &val);
	}
	ft_fill_px(data, val.x2 - 200,
			val.y2 + 200, data->first_link->color);
}
*/
