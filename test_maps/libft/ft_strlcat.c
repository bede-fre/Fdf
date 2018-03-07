/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:13:44 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/24 11:56:59 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dlen;
	unsigned int	slen;

	i = -1;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	while (src[++i] != '\0' && (dlen + i) < (size - 1))
		dst[dlen + i] = src[i];
	dst[dlen + i] = '\0';
	if (dlen < size)
		return (slen + dlen);
	return (slen + size);
}
