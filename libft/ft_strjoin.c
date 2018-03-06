/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:18:10 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 16:55:44 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	i;
	size_t	len;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((tab = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while ((++i) < ft_strlen(s1))
		tab[i] = s1[i];
	len = 0;
	while (len < ft_strlen(s2))
		tab[i++] = s2[len++];
	tab[i] = '\0';
	return (tab);
}
