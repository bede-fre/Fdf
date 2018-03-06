/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:22:55 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/23 16:22:47 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	i = -1;
	tab1 = (unsigned char*)s1;
	tab2 = (unsigned char*)s2;
	while ((++i) < n)
	{
		if (tab1[i] > tab2[i])
			return (tab1[i] - tab2[i]);
		if (tab1[i] < tab2[i])
			return (tab1[i] - tab2[i]);
		if (tab1[i] == '\0' && tab2[i] == '\0')
			return ('\0');
	}
	return (0);
}
