/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:17:37 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 16:56:51 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tab;

	i = 0;
	tab = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	tab = (char*)malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		tab[i] = (*f)(i, (char)s[i]);
	tab[i] = '\0';
	return (tab);
}
