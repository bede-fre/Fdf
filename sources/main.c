/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/05 16:00:54 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_picture(t_values *val)
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

int			main(int ac, char **av)
{
	int			fd;
	t_values	*val;
	char		*line;

	if (ac == 6)
	{
		fd = open(av[1], O_RDONLY);
		val = ft_read_stock(fd, &line);
		close(fd);
		ft_size_window(val, av[4], av[5]);
		ft_compare_color(ft_atoi_base(av[2], 16), ft_atoi_base(av[3], 16), val);
		ft_picture(val);
		ft_free_lst(&val->first_link);
		free(val);
		free(line);
	}
	else
	{
		ft_putstr_fd("usage : ./fdf [filename.fdf] color_bottom [0x******]", 2);
		ft_putstr_fd(" color_top [0x******] lenght_window [unsigned short]", 2);
		ft_putendl_fd(" widht_window [unsigned short]", 2);
	}
	return (0);
}
