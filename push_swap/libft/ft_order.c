/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:22:27 by prawney           #+#    #+#             */
/*   Updated: 2019/01/27 19:11:10 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_order(unsigned int num)
{
	int		order;

	if (num == 0)
		return (1);
	order = 0;
	while (num > 0)
	{
		num /= 10;
		order++;
	}
	return (order);
}
