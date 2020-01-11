/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:16:58 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/01 19:51:03 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*row_dst;
	unsigned char	*row_src;

	row_dst = (unsigned char*)dst;
	row_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		row_dst[i] = row_src[i];
		if (row_src[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		++i;
	}
	return (NULL);
}
