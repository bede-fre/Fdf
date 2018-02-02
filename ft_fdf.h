/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:53:11 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/02 16:03:01 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WHITE_COLOR 0xFFFFFF

typedef struct		s_stock
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_stock	*n_x;
	struct s_stock	*n_y;
	struct s_stock	*p_x;
	struct s_stock	*p_y;
}					t_stock;

typedef struct		s_values
{
	int				x_max;
	int				y_max;
	int				ln;
	int				cl;
	struct s_stock	*tp_y;
	struct s_stock	*tp_x;
	struct s_stock	*first_link;
	struct s_stock	*first_x;
}					t_values;





#endif
