/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:47:13 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/30 16:47:40 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	ft_get_char(int fd, t_struct *t_gnl)
{
	char			c;

	if (t_gnl->l == 0)
	{
		if ((t_gnl->temp = read(fd, t_gnl->buff, BUFF_SIZE)) <= 0)
			return ((t_gnl->temp == 0) ? 0 : -1);
		t_gnl->tp = t_gnl->buff;
		t_gnl->l = t_gnl->temp;
	}
	c = *t_gnl->tp;
	t_gnl->tp++;
	t_gnl->l--;
	return (c);
}

int		ft_gnl(const int fd, char **line)
{
	int				len;
	char			c;
	static t_struct	t_gnl;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	len = 0;
	c = ft_get_char(fd, &t_gnl);
	if (t_gnl.temp <= 0)
		return ((t_gnl.temp == 0) ? 0 : -1);
	while (c != '\n' && t_gnl.temp > 0)
	{
		line[0][len] = c;
		c = ft_get_char(fd, &t_gnl);
		len++;
		if ((len % BUFF_SIZE) == 0)
			*line = ft_realloc(*line, len + BUFF_SIZE + 1);
	}
	line[0][len] = '\0';
	if (c == 0 && line[0][0] == 0)
		return (0);
	return (1);
}
