/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:53:11 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/08 10:23:45 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stock
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				a;
	int				b;
	struct s_stock	*n_x;
	struct s_stock	*n_y;
	struct s_stock	*p_x;
	struct s_stock	*p_y;
}					t_stock;

typedef struct		s_col
{
	unsigned char	r1;
	unsigned char	g1;
	unsigned char	b1;
	unsigned char	r2;
	unsigned char	g2;
	unsigned char	b2;
	short			d_r1;
	short			d_g1;
	short			d_b1;
	short			d_r2;
	short			d_g2;
	short			d_b2;
	unsigned char	l_s_r;
	unsigned char	l_s_g;
	unsigned char	l_s_b;
	unsigned char	l_e_r;
	unsigned char	l_e_g;
	unsigned char	l_e_b;
}					t_col;

typedef struct		s_algo
{
	int				da;
	int				db;
	int				i;
	int				cpta;
	int				cptb;
	int				cumul;
	int				a;
	int				b;
}					t_algo;

typedef struct		s_draw
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*s_px;
	int				endian;
	int				bpp;
	int				sz_ln_px;
	double			zoom;
	double			l_win;
	double			w_win;
	int				var_x;
	int				var_y;
	double			r;
}					t_draw;

typedef struct		s_values
{
	char			**tab;
	int				x_max;
	int				y_max;
	int				ln;
	int				cl;
	int				z_min;
	int				z_max;
	int				z_range;
	char			first;
	t_stock			*tp_y;
	t_stock			*tp_x;
	t_stock			*first_link;
	t_stock			*last_link;
	t_stock			*first_x;
	t_col			col;
	t_algo			algo;
	t_draw			draw;
}					t_values;



#endif
