/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:43:05 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 11:27:02 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tp;

	tp = (char*)s;
	while ((*s == '\0') && (c == '\0'))
		return ((char*)s);
	while (*s != '\0')
		s++;
	while (*tp != '\0')
	{
		if (*s != c)
		{
			s--;
			tp++;
		}
		if (*s == c)
			return ((char*)s);
	}
	return (NULL);
}
