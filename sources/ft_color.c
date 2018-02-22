/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:51:52 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/22 16:43:53 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_val_z_stock(t_values *val, char **tp)
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
		if(val->z_max > ft_atoi(tp[0]))
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

void		ft_compare_color(int cl1, int cl2, t_values *val)
{
	// RGB Depart Color
	val->color->r1 = (unsigned char)(cl1 >> 16);
	val->color->g1 = (unsigned char)(cl1 >> 8);
	val->color->b1 = (unsigned char)(cl1);
	
	// RGB End Color
	val->color->r2 = (unsigned char)(cl2 >> 16);
	val->color->g2 = (unsigned char)(cl2 >> 8);
	val->color->b2 = (unsigned char)(cl2);
	
	// RGB Delta Color End - Depart
	val->color->d_r1 = (short)(val->color->r2 - val->color->r1);
	val->color->d_g1 = (short)(val->color->g2 - val->color->g1);
	val->color->d_b1 = (short)(val->color->b2 - val->color->b1);

	// RGB Delta Color Depart - End
	val->color->d_r2 = (short)(val->color->r1 - val->color->r2);
	val->color->d_g2 = (short)(val->color->g1 - val->color->g2);
	val->color->d_b2 = (short)(val->color->b1 - val->color->b2);
}

void		ft_gradient_color(t_values *val, t_stock *lst, t_stock *next)
{
	float l_s;
	float l_e;
	
	if (lst->z >= next->z)
	{
		// start link
		l_s = ((float)(lst->z - val->z_min) / (float)val->z_range);

		// end link
		l_e = ((float)(next->z - val->z_min) / (float)val->z_range);

		// RGB recalculate for start link
		val->color->l_s_r = (int)((float)((val->color->r1) + ((float)(val->color->d_r1) * l_s)));
		val->color->l_s_g = (int)((float)((val->color->g1) + ((float)(val->color->d_g1) * l_s)));
		val->color->l_s_b = (int)((float)((val->color->b1) + ((float)(val->color->d_b1) * l_s)));

		// RGB recalculate for end link
		val->color->l_e_r = (int)((float)((val->color->r1) + ((float)(val->color->d_r1) * l_e)));
		val->color->l_e_g = (int)((float)((val->color->g1) + ((float)(val->color->d_g1) * l_e)));
		val->color->l_e_b = (int)((float)((val->color->b1) + ((float)(val->color->d_b1) * l_e)));
	}
	else
	{
		// start link
		l_s = ((float)(lst->z + val->z_min) / (float)val->z_range);

		// end link
		l_e = ((float)(next->z + val->z_min) / (float)val->z_range);
// RGB recalculate for start link
		val->color->l_s_r = (int)((float)((val->color->r2) + ((float)(val->color->d_r2) * l_s)));
		val->color->l_s_g = (int)((float)((val->color->g2) + ((float)(val->color->d_g2) * l_s)));
		val->color->l_s_b = (int)((float)((val->color->b2) + ((float)(val->color->d_b2) * l_s)));

		// RGB recalculate for end link
		val->color->l_e_r = (int)((float)((val->color->r2) + ((float)(val->color->d_r2) * l_e)));
		val->color->l_e_g = (int)((float)((val->color->g2) + ((float)(val->color->d_g2) * l_e)));
		val->color->l_e_b = (int)((float)((val->color->b2) + ((float)(val->color->d_b2) * l_e)));
	}

	// Delta RGB for pixel start link and pixel end link
	val->color->d_r_px = (short)(val->color->l_e_r - val->color->l_s_r);
	val->color->d_g_px = (short)(val->color->l_e_g - val->color->l_s_g);
	val->color->d_b_px = (short)(val->color->l_e_b - val->color->l_s_b);
}


int			ft_merge_color(unsigned char red, unsigned char green, unsigned char blue)
{
	return ((int)(red << 16) | (int)(green << 8) | (int)(blue));
}
