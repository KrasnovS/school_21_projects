/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:18:36 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/26 23:00:09 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*row_dst;
	const unsigned char	*row_src;

	row_dst = (unsigned char *)dst;
	row_src = (unsigned char *)src;
	if (row_src == row_dst)
		return (dst);
	i = 0;
	if (row_src < row_dst)
		while (++i <= len)
			row_dst[len - i] = row_src[len - i];
	else
		while (len-- > 0)
			*(row_dst++) = *(row_src++);
	return (dst);
}
