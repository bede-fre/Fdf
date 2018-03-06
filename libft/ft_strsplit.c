/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:14:21 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/24 14:13:19 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wd(char const *s, int i, char c)
{
	int		a;

	a = 0;
	while (s[a + i] != c && s[a + i])
		a++;
	a += 1;
	return (a);
}

static char	**ft_malloc_wd(char const *s, int wd, char c, int y)
{
	char	**tab;
	int		i;
	int		x;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * (wd + 1))) == NULL)
		return (NULL);
	while (++y < wd)
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			if ((tab[y] = (char*)malloc(sizeof(char) * ft_wd(s, i, c))) == NULL)
				return (NULL);
			x = 0;
			while (s[i] != c && s[i])
				tab[y][x++] = s[i++];
			tab[y][x] = '\0';
		}
	}
	tab[y] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
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
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
		{
			wd++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	tab = (ft_malloc_wd(s, wd, c, y));
	return (tab);
}
