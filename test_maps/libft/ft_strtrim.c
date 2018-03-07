/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:41:52 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 16:58:24 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_malloc(int i, int no_blank, char const *s, char *tab)
{
	int i2;

	i2 = 0;
	if ((tab = (char*)malloc(sizeof(char) * (no_blank + 1))) == NULL)
		return (NULL);
	while ((no_blank--) > 0)
	{
		tab[i2] = s[i2 + i];
		i2++;
	}
	tab[i2] = '\0';
	return (tab);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		i2;
	int		len;
	int		no_blank;
	char	*tab;

	i = 0;
	i2 = 0;
	tab = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if ((len - i) <= 0)
		return (ft_strdup(""));
	while ((len--) > 0 && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		i2++;
	no_blank = ft_strlen(s) - (i + i2);
	if (len - i <= 0)
		return (ft_strdup(""));
	return (ft_malloc(i, no_blank, s, tab));
}
