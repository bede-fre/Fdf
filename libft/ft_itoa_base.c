/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:52:47 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/24 13:08:49 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_tabret(char *tab, int n, unsigned int a, int base)
{
	int i;

	i = 0;
	while (a > 0)
	{
		if (a % base < 10)
			tab[i++] = (a % base) + '0';
		else
			tab[i++] = (a % base) - 10 + 'A';
		a /= base;
	}
	if ((n < 0) && (base == 10))
		tab[i] = '-';
	return (tab);
}

char		*ft_itoa_base(int n, int base)
{
	unsigned int	a;
	int				i;
	char			*tab;

	if (base < 2 && base > 16)
		return (NULL);
	tab = 0;
	i = ((n < 0) && (base == 10)) ? 1 : 0;
	a = (n < 0 ? -n : n);
	if (n == 0)
	{
		if (!(tab = ft_strnew(1)))
			return (NULL);
		tab[0] = '0';
		return (tab);
	}
	while (a /= base)
		i++;
	if (!(tab = ft_strnew(++i)))
		return (NULL);
	a = (n < 0 ? -n : n);
	ft_strrev(ft_tabret(tab, n, a, base));
	return (tab);
}
