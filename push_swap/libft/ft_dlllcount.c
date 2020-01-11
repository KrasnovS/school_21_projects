/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlllcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:19:34 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 17:56:54 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlllcount(t_dllist *addr)
{
	int		count;

	if (addr == NULL)
		return (0);
	count = 0;
	while (addr != NULL)
	{
		count++;
		addr = addr->left;
	}
	return (count);
}
