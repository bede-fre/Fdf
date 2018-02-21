/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:51:52 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/21 16:30:23 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_val_z_stock(t_values *val, char **tp)
{
	static	int	i;

	if (ft_atol(tp[0]) > 2147483647 || ft_atol(tp[0]) < -2147483648)
	{
		
		exit(1);
	}
	if (i++ == 0)
	{
		val->z_min = ft_atoi(tp[0]);
		val->z_max = ft_atoi(tp[0]);
	}
	else
	{
		if (val->z_min < ft_atoi(tp[0]))
			val->z_min =  val->z_min;
		else
			val->z_min = ft_atoi(tp[0]);
		if(val->z_max > ft_atoi(tp[0]))
			val->z_max =  val->z_max;
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
	while (tp != val->z_max)
	{
		tp++;
		i++;
	}
	val->z_range = i;
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
	val->color->d_r = val->color->r2 - val->color->r1;
	val->color->d_g = val->color->g2 - val->color->g1;
	val->color->d_b = val->color->b2 - val->color->b1;
}

void		ft_gradient_color(t_values *val, t_stock *lst, t_stock *next)
{
	float l_s;
	float l_e;

	if(!(val->color = (t_color*)ft_memalloc(sizeof(t_color))))
		exit(1);
	
	// Start link
	l_s = ((float)(lst->z - val->z_min) / (float)val->z_range);
	
	// End link
	l_e = ((float)(next->z - val->z_min) / (float)val->z_range);
	
	ft_compare_color(val->cl_s, val->cl_e, val);
	
	// RGB recalculate for start link
	val->color->l_s_r = (int)((float)((val->color->r1) + ((float)(val->color->d_r) * l_s)));
	val->color->l_s_g = (int)((float)((val->color->g1) + ((float)(val->color->d_g) * l_s)));
	val->color->l_s_b = (int)((float)((val->color->b1) + ((float)(val->color->d_b) * l_s)));

	// RGB recalculate for end link
	val->color->l_e_r = (int)((float)((val->color->r2) + ((float)(val->color->d_r) * l_e)));
	val->color->l_e_g = (int)((float)((val->color->g2) + ((float)(val->color->d_g) * l_e)));
	val->color->l_e_b = (int)((float)((val->color->b2) + ((float)(val->color->d_b) * l_e)));
	

	
	ft_putnbr(val->color->l_e_r);
	ft_putchar(' ');
	ft_putnbr(val->color->l_e_g);
	ft_putchar(' ');
	ft_putnbr(val->color->l_e_b);


		/*| (int)((val->color.g1) + (val->color.d_g * l_s))
		| (int)((val->color.b1) + (val->color.d_b * l_s));*/
	
}
