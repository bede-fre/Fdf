/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:51:52 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/13 12:49:36 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_fdf.h"

void		ft_val_z_stock(t_values *val, char **tp)
{
	static	int	i;

	if (ft_atol(tp[0]) > 2147483647 || ft_atol(tp[0]) < -2147483648)
	{
		
		exit(1);
	}
	if (++i == 1)
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
	val->z_range = val->z_max - val->z_min;
}
