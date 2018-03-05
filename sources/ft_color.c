/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:51:52 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/05 15:21:49 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_val_z_stock(t_values *val, char **tp)
{
	static	int	i;

	if (ft_atol(tp[0]) > 2147483647 || ft_atol(tp[0]) < -2147483648)
		exit(1);
	if (i++ == 0)
	{
		val->z_min = ft_atoi(tp[0]);
		val->z_max = ft_atoi(tp[0]);
	}
	else
	{
		if (val->z_min < ft_atoi(tp[0]))
			val->z_min = val->z_min;
		else
			val->z_min = ft_atoi(tp[0]);
		if (val->z_max > ft_atoi(tp[0]))
			val->z_max = val->z_max;
		else
			val->z_max = ft_atoi(tp[0]);
	}
}

void	ft_color_range(t_values *val)
{
	int	i;
	int	tp;

	i = 0;
	tp = val->z_min;
	if (tp == val->z_max)
		val->z_range = 1;
	else
	{
		while (tp != val->z_max)
		{
			tp++;
			i++;
		}
		val->z_range = i;
	}
}

void	ft_compare_color(int cl1, int cl2, t_values *val)
{
	val->col.r1 = (unsigned char)(cl1 >> 16);
	val->col.g1 = (unsigned char)(cl1 >> 8);
	val->col.b1 = (unsigned char)(cl1);
	val->col.r2 = (unsigned char)(cl2 >> 16);
	val->col.g2 = (unsigned char)(cl2 >> 8);
	val->col.b2 = (unsigned char)(cl2);
	val->col.d_r1 = (short)(val->col.r2 - val->col.r1);
	val->col.d_g1 = (short)(val->col.g2 - val->col.g1);
	val->col.d_b1 = (short)(val->col.b2 - val->col.b1);
	val->col.d_r2 = (short)(val->col.r1 - val->col.r2);
	val->col.d_g2 = (short)(val->col.g1 - val->col.g2);
	val->col.d_b2 = (short)(val->col.b1 - val->col.b2);
}

void	ft_gradient_color(t_values *val, t_stock *lst, t_stock *next)
{
	float l_s;
	float l_e;

	if (lst->z >= next->z)
	{
		l_s = ((float)(lst->z - val->z_min) / (float)val->z_range);
		val->col.l_s_r = (int)((float)((val->col.r1)
			+ ((float)(val->col.d_r1) * l_s)));
		val->col.l_s_g = (int)((float)((val->col.g1)
			+ ((float)(val->col.d_g1) * l_s)));
		val->col.l_s_b = (int)((float)((val->col.b1)
			+ ((float)(val->col.d_b1) * l_s)));
	}
	else
	{
		l_e = ((float)(next->z - val->z_max) / (float)val->z_range);
		val->col.l_s_r = (int)((float)((val->col.r2)
			- ((float)(val->col.d_r2) * l_e)));
		val->col.l_s_g = (int)((float)((val->col.g2)
			- ((float)(val->col.d_g2) * l_e)));
		val->col.l_s_b = (int)((float)((val->col.b2)
			- ((float)(val->col.d_b2) * l_e)));
	}
}

int		ft_merge_color(unsigned char red, unsigned char green,
			unsigned char blue)
{
	return ((int)(red << 16) | (int)(green << 8) | (int)(blue));
}
