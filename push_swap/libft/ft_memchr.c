/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:05:52 by prawney           #+#    #+#             */
/*   Updated: 2018/12/18 21:08:21 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*area;
	unsigned char	chr;
	size_t			i;

	area = (unsigned char*)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (area[i] == chr)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
