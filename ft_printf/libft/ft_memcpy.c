/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:43:46 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/26 22:13:46 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*row;
	const unsigned char	*row2;

	if (!n || (!dst && !src))
		return (dst);
	row = (unsigned char*)dst;
	row2 = (unsigned char*)src;
	while (n-- > 0)
		*(row++) = *(row2++);
	return (dst);
}
