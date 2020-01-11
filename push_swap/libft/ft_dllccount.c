/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllccount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:21:17 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 17:44:02 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dllccount(t_dllist *addr)
{
	t_dllist	*left;
	int			count;

	if (addr == NULL)
		return (0);
	left = addr->left;
	count = 0;
	while (addr != NULL)
	{
		count++;
		addr = addr->right;
	}
	while (left != NULL)
	{
		count++;
		addr = addr->left;
	}
	return (count);
}
