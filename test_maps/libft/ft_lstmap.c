/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:56:28 by bede-fre          #+#    #+#             */
/*   Updated: 2017/11/29 16:35:11 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alst;
	t_list	*tp;

	if (lst == NULL || f == NULL)
		return (NULL);
	alst = f(lst);
	tp = alst;
	while (lst->next)
	{
		alst->next = f(lst->next);
		alst = alst->next;
		lst = lst->next;
	}
	return (tp);
}
