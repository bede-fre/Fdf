/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:49:13 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/29 10:58:29 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int cpt;
	int res;

	cpt = 1;
	res = 1;
	if (power <= 0)
		return (power == 0 ? 1 : 0);
	while (cpt++ <= power)
		res = res * nb;
	return (res);
}
