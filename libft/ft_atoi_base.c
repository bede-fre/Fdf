/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:11:42 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/29 18:20:08 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_str_upcase(char *s)
{
	int				i;

	i = -1;
	while (s[++i])
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = ft_toupper(s[i]);
}

static int	ft_check(char *s, int i, int base, int *neg)
{
	while (ft_isspace(s[i]))
		i++;
	if ((s[i] == '-' || s[i] == '+') && s[i + 1] == '0')
		return (0);
	if ((s[i] == '-' || s[i] == '+') && base == 10)
	{
		*neg = (s[i] == '-') ? 1 : 0;
		i++;
	}
	else if (s[i] == '0')
	{
		if (s[i + 1] == 'X' && base != 16)
			return (0);
		i += 2;
	}
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] < ('0' + base))
			|| (s[i] >= 'A' && s[i] < ('A' + base - 10)))
			i++;
		else
			return (0);
	}
	return (1);
}

int			ft_atoi_base(char *s, int base)
{
	int				p;
	int				neg;
	int				i;
	unsigned int	ret;

	i = 0;
	neg = 0;
	ret = 0;
	p = 0;
	ft_str_upcase(s);
	if ((base < 2 || base > 16) || ft_check(s, i, base, &neg) == 0)
		return (0);
	ft_strrev(s);
	i = 0;
	while (s[i] && (s[i] != '-' && s[i] != '+' && s[i] != 'X'))
	{
		if (s[i] >= '0' && s[i] < ('0' + base))
			ret += (s[i++] - '0') * ft_power(base, p++);
		else if (s[i] >= 'A' && (s[i] < ('A' + (base - 10))))
			ret += (s[i++] + 10 - 'A') * ft_power(base, p++);
	}
	if (neg == 1)
		return (-ret);
	return (ret);
}
