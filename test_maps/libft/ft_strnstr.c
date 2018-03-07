/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:18:37 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/28 15:17:53 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ln;

	ln = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while ((*haystack != '\0') && (ln <= len--))
	{
		if ((*haystack == *needle) && (ft_strncmp(haystack, needle, ln) == 0))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
