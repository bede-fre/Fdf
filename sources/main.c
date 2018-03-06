/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/06 13:36:32 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void		ft_usage(void)
{
	ft_putstr_fd("usage : ./fdf [filename.fdf] color_bottom [0x******]", 2);
	ft_putstr_fd(" color_top [0x******] lenght_window [unsigned short]", 2);
	ft_putendl_fd(" widht_window [unsigned short]", 2);
	exit(1);
}

static void		ft_params_window(t_values *val, char *len, char *wid)
{
	val->draw.l_win = (double)(ft_atoi(len));
	val->draw.w_win = (double)(ft_atoi(wid));
	val->draw.var_x = (int)(val->draw.l_win / 2.0);
	val->draw.var_y = (int)(val->draw.w_win / 2.0);
	val->draw.zoom = 0.2;
	val->draw.r = 0.0 * (M_PI / 180.0);
}

static void		ft_compare_color(int cl1, int cl2, t_values *val)
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

static void		ft_init_image(t_values *val)
{
	ft_color_range(val);
	val->draw.mlx = mlx_init();
	val->draw.win = mlx_new_window(val->draw.mlx, val->draw.w_win,
		val->draw.l_win, "FdF");
	val->draw.img = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px = mlx_get_data_addr(val->draw.img, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	ft_display(val, val->first_link);
	mlx_key_hook(val->draw.win, ft_deal_key, val);
	mlx_loop(val->draw.mlx);
}

int				main(int ac, char **av)
{
	int			fd;
	t_values	*val;
	char		*line;

	if (ac != 6)
		ft_usage();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error("Nonexistent file");
	val = ft_read_stock(fd, &line);
	ft_params_window(val, av[4], av[5]);
	ft_compare_color(ft_atoi_base(av[2], 16), ft_atoi_base(av[3], 16), val);
	ft_init_image(val);
	ft_free_lst(&val->first_link);
	free(val);
	free(line);
	if (close(fd) == -1)
		ft_error("Failed to close correctly file descriptor");
	return (0);
}
