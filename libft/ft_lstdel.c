/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:25:19 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 16:33:51 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *blst;
	t_list *tp;

	blst = *alst;
	while (blst != NULL)
	{
		tp = blst->next;
		ft_lstdelone(&blst, del);
		free(blst);
		blst = tp;
	}
	*alst = NULL;
}
