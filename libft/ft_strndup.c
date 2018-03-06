/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:12:58 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/24 14:08:58 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ret;
	size_t	i;

	if ((ret = (char*)ft_memalloc(n + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i < n && s1[i])
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}
