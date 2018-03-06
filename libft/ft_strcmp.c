/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:10:18 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 16:50:28 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	i = -1;
	tab1 = (unsigned char*)s1;
	tab2 = (unsigned char*)s2;
	while (tab1[++i] != '\0' || tab2[i] != '\0')
	{
		if (tab1[i] > tab2[i])
			return (tab1[i] - tab2[i]);
		if (tab1[i] < tab2[i])
			return (tab1[i] - tab2[i]);
	}
	return (0);
}
