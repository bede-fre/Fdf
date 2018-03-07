/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:14:21 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/26 10:49:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wd(char const *s, int i)
{
	int		a;

	a = 0;
	while (!ft_isspace(s[a + i]) && s[a + i])
		a++;
	a += 1;
	return (a);
}

static char	**ft_malloc_wd(char const *s, int wd, int y)
{
	char	**tab;
	int		i;
	int		x;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * (wd + 1))) == NULL)
		return (NULL);
	while (++y < wd)
	{
		while (ft_isspace(s[i]) && s[i])
			i++;
		if (s[i])
		{
			if ((tab[y] = (char*)malloc(sizeof(char) * ft_wd(s, i))) == NULL)
				return (NULL);
			x = 0;
			while (!ft_isspace(s[i]) && s[i])
				tab[y][x++] = s[i++];
			tab[y][x] = '\0';
		}
	}
	tab[y] = 0;
	return (tab);
}

char		**ft_split_whitespaces(char const *s)
{
	int		i;
	int		wd;
	int		y;
	char	**tab;

	i = 0;
	wd = 0;
	y = -1;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		while (ft_isspace(s[i]) && s[i])
			i++;
		if (s[i] && !ft_isspace(s[i]))
		{
			wd++;
			while (!ft_isspace(s[i]) && s[i])
				i++;
		}
	}
	tab = (ft_malloc_wd(s, wd, y));
	return (tab);
}
