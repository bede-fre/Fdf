/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:31:44 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 16:39:14 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*sdst;
	const char	*ssrc;

	sdst = (char *)dst;
	ssrc = (const char*)src;
	if (dst > src)
		while (len--)
			sdst[len] = ssrc[len];
	else
		dst = ft_memcpy(sdst, ssrc, len);
	return (dst);
}
