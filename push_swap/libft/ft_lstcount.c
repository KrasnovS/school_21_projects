/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:36:41 by prawney           #+#    #+#             */
/*   Updated: 2018/12/20 21:55:13 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *addr)
{
	int		count;

	if (addr == NULL)
		return (0);
	count = 0;
	while (addr != NULL)
	{
		count++;
		addr = addr->next;
	}
	return (count);
}
