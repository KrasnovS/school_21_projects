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
	unsigned int	i;
	unsigned char	*str_dest;
	unsigned char	*str_src;

	i = 0;
	str_dest = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		if (str_dest[i] == (unsigned char)c)
			return ((void *)&str_dest[i + 1]);
		i++;
	}
	return (NULL);
}
