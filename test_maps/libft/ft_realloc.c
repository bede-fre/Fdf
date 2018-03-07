/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 08:56:45 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/24 17:34:23 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	char	*str;

	if (ptr == NULL)
	{
		if (!(ptr = (char*)malloc(size)))
			return (NULL);
		return (ptr);
	}
	if (size == 0)
	{
		if (!(str = (char*)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (str);
	}
	else
	{
		str = ptr;
		if (!(ptr = (char*)malloc(size)))
			return (NULL);
		ft_strncpy(ptr, str, size);
		ft_memdel((void*)&str);
	}
	return (ptr);
}
