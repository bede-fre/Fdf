/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:53:11 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/05 17:18:45 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WHITE 0xFFFFFF
# define CARROT_ORANGE 0xE58E26
# define JALAPENO_RED 0xB71540
# define AZRAQ_BLUE 0x4A69BD
# define DUPAIN 0x60A3BC
# define REEF_ENCOUNTER 0x079992

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
	int				x_max;
	int				y_max;
	int				ln;
	int				cl;
	int				z_min;
	int				z_max;
	int				z_range;
	t_stock			*tp_y;
	t_stock			*tp_x;
	t_stock			*first_link;
	t_stock			*last_link;
	t_stock			*first_x;
	t_col			col;
	t_algo			algo;
	t_draw			draw;
}					t_values;

void				ft_size_window(t_values *val, char *len, char *wid);
void				ft_display(t_values *val, t_stock *list);
int					ft_deal_key(int key, t_values *val);
void				ft_fill_px(t_values *val, int x, int y, int color);
void				ft_find_middle_link(t_values *val, t_stock *lst);
void				ft_compare_color(int cl1, int cl2, t_values *val);
void				ft_gradient_color(t_values *val, t_stock *lst, t_stock *next);
void				ft_val_z_stock(t_values *val, char **tp);
void				ft_color_range(t_values *val);
void				ft_free_lst(t_stock **list);
void				ft_stock_x_max(t_values *val);
void				ft_quit_line_more(t_values *val);
void				ft_quit_line_less(t_values *val);
void				ft_proj_iso(t_stock *lst, t_stock *st, t_values *val);
void				ft_fill_px(t_values *val, int x, int y, int color);
void				ft_algo(t_values *val, t_stock *lst, t_stock *st, int color);
int					ft_merge_color(unsigned char red, unsigned char green, unsigned char blue);
t_values			*ft_read_stock(int fd, char **line);

#endif
