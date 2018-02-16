/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/16 17:27:30 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_print_list(t_stock *list)
{
	t_stock	*line;
	char	*nbr;

	while (list)
	{
		line = list;
		while (line)
		{
			ft_putnbr(line->z);
			if (line->color)
			{
				ft_putstr(",0x");
				nbr = ft_itoa_base(line->color, 16);
				ft_putstr(nbr);
				ft_memdel((void*)&nbr);
			}
			if (line->n_x != NULL)
				ft_putchar(' ');
			line = line->n_x;
		}
		ft_putchar('\n');
		list = list->n_y;
	}
}
/*
static void	ft_revdisplay(t_stock *list)
{
	t_stock	*line;
	char	*nbr;

	while (list)
	{
		line = list;
		while (line)
		{
			ft_putnbr(line->z);
			if (line->color)
			{
				ft_putstr(",0x");
				 nbr = ft_itoa_base(line->color, 16);
				ft_putstr(nbr);
				ft_memdel((void*)&nbr);
			}
			if (line->p_x != NULL)
				ft_putchar(' ');
			line = line->p_x;
		}
		ft_putchar('\n');
		list = list->p_y;
	}
}*/
/*
int		ft_color(unsigned char alpha, unsigned char blue, unsigned char green, unsigned char red)
{
	return ((int)(alpha << 24) | (int)(red << 16) | (int)(green << 8)
			| (int)(blue));
}*/

// Function return 1 for little endian or 0 for big endian
/*
void ft_check_endianness(t_values *data)
{
	unsigned int	i;
	char			*s;
		
	i = 1;
	s = (char*) &i;
	data->endian = (int)*s;
}
*/

int		ft_close_win(int key, t_values *data)
{
	(void)key;
	(void)data;
	ft_free_lst(&data->first_link);
	exit(0);
	return (0);
}

int		ft_deal_key(int key, t_values *data)
{
	if (key == 53)
	{
		ft_free_lst(&data->first_link);
		exit(0);
	}
	return (0);
}


int		ft_deal_keymouse(int key, int x, int y, t_values *data)
{
	(void)x;
	(void)y;
	(void)data;
	if (key == 4)
	{
		exit(0);
	}
	return (0);
}


void	ft_fill_px(unsigned char *s_px, int x, int y, int color)
{
	(void)x;
	(void)y;
	//(void)color;

	s_px[0] = (unsigned char)(color);
	s_px[1] = (unsigned char)(color >> 8);
	s_px[2] = (unsigned char)(color >> 16);
	s_px[3] = (unsigned char)(0);

	s_px[4] = (unsigned char)(color);
	s_px[5] = (unsigned char)(color >> 8);
	s_px[6] = (unsigned char)(color >> 16);
	s_px[7] = (unsigned char)(0);

	s_px[8] = (unsigned char)(color);
	s_px[9] = (unsigned char)(color >> 8);
	s_px[10] = (unsigned char)(color >> 16);
	s_px[11] = (unsigned char)(0);

	s_px[12] = (unsigned char)(color);
	s_px[13] = (unsigned char)(color >> 8);
	s_px[14] = (unsigned char)(color >> 16);
	s_px[15] = (unsigned char)(0);

	s_px[16] = (unsigned char)(color);         //BLUE
	s_px[17] = (unsigned char)(color >> 8);         //GREEN
	s_px[18] = (unsigned char)(color >> 16);       //RED
	s_px[19] = (unsigned char)(0);            //ALPHA
	
}

/*
void	ft_square(int l, int w, int x, int y, t_values *data)
{
	int	s_x;
	int	s_y;
	int	tp_l;
	int	tp_w;

	s_x = x;
	s_y = y;
	tp_l = l;
	tp_w = w;
	mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
	while(--w > 0)
		mlx_pixel_put(data->mlx, data->win, s_x--, s_y, 0xFF0000);
	while(--l > 0)
		mlx_pixel_put(data->mlx, data->win, s_x, s_y--, 0x00FF00);
	while(++w < tp_w)
		mlx_pixel_put(data->mlx, data->win, s_x++, s_y, 0x0000FF);
	while(++l < tp_l)
		mlx_pixel_put(data->mlx, data->win, s_x, s_y++, 0xFFFFFF);
}
*/



int	main(int ac, char **av)
{
	int			i;
	int			fd;
	t_values	*data;
	char		*line;
	
	i = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		data = ft_read_stock(fd, &line);
		ft_print_list(data->first_link);

		//ft_revdisplay(data->tp_x);
		//ft_color_range(data);

		close(fd);
		//ft_check_endianness(data);

		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx,500,500, "FdF");
		data->img = mlx_new_image(data->mlx, 500, 500);
		//mlx_pixel_put(data->mlx, data->win, 250, 250, 0xFFFFFF);
		//ft_square(50, 50, 250, 250, data);
		data->s_px = mlx_get_data_addr(data->img, &data->bpp, &data->sz_ln_px, &data->endian);
		ft_fill_px((unsigned char*)data->s_px, 0, 0, 0x82E0AA);

		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_mouse_hook(data->win, ft_deal_keymouse, data);
		mlx_key_hook(data->win, ft_deal_key, data);
		mlx_hook(data->win, 17, (1L<<17), &ft_close_win, data);
		mlx_loop(data->mlx);
		ft_free_lst(&data->first_link);
		free(data);
		free(line);
	}
	else
		ft_putendl_fd("usage : ./fdf [filename.fdf]", 2);
	return (0);
}
