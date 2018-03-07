/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:44:26 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/24 14:00:38 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_tabret(char *tab, int n, unsigned int a)
{
	int i;

	i = 0;
	while (a > 0)
	{
		tab[i++] = (a % 10) + '0';
		a /= 10;
	}
	if (n < 0)
		tab[i] = '-';
	return (tab);
}

char		*ft_itoa(int n)
{
	unsigned int	a;
	int				i;
	char			*tab;

	tab = 0;
	i = (n < 0) ? 1 : 0;
	a = (n < 0) ? -n : n;
	if (n == 0)
	{
		if (!(tab = ft_strnew(1)))
			return (NULL);
		tab[0] = '0';
		return (tab);
	}
	while (a /= 10)
		i++;
	if (!(tab = ft_strnew(++i)))
		return (NULL);
	a = (n < 0) ? -n : n;
	ft_strrev(ft_tabret(tab, n, a));
	return (tab);
}
