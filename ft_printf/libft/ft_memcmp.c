/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:31:13 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/18 21:07:09 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sow1;
	unsigned char	*sow2;

	i = 0;
	sow1 = (unsigned char*)s1;
	sow2 = (unsigned char*)s2;
	while (i < n)
	{
		if (sow1[i] != sow2[i])
			return ((unsigned char)sow1[i] - (unsigned char)sow2[i]);
		i++;
	}
	return (0);
}
