/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:06:20 by prawney           #+#    #+#             */
/*   Updated: 2018/12/15 18:49:02 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*area;

	if (size == 0)
		return (NULL);
	if (!(area = (void*)malloc(sizeof(*area) * size)))
		return (NULL);
	while (size > 0)
	{
		area[size - 1] = 0;
		size--;
	}
	return (area);
}
