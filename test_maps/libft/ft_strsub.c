/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:22:16 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 16:57:39 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	i;
	int				i2;

	i = start + len;
	i2 = 0;
	if (s == NULL)
		return (NULL);
	if ((tab = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (start < i)
		tab[i2++] = s[start++];
	tab[i2] = '\0';
	return (tab);
}
