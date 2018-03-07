/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:52:53 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 16:56:21 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f) (char))
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if ((tab = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		tab[i] = (*f)((char)s[i]);
	tab[i] = '\0';
	return (tab);
}
