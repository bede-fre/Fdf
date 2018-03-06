/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:33:29 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/30 09:49:35 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*tab;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if ((tab = (char*)ft_memalloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		tab[i] = s1[i];
	tab[i] = '\0';
	return (tab);
}
