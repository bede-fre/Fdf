/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oakenshield.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:11:28 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/26 14:43:14 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_atoi_base(char *s, int base)
{
{
	int				neg;
	int				i;
	unsigned int	ret;

	i = 0;
	neg = 0;
	ret = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
		neg = 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
	{
		ret *= 10;
		ret += s[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-ret);
	return (ret);
}

t_stock	*ft_stock_check(int fd, char **line)
{
	int		y;
	int		i;
	char	**tab;
	t_stock *data;

	y = 0;
	i = 0;
	while (ft_gnl(fd, line) == 1)
	{
		while (*line)
		{
			if () )
			tab = ft_split_whitespaces(*line);

		}
	
	
	}



}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY) == -1))
			return (-1);
		ft_stock_check(fd, &line);
		if (close(fd) == -1)
			return (-1);
	}
	else
		ft_putendl_fd("usage : ./fdf [filename.fdf]", 2);
	return (0);
}
