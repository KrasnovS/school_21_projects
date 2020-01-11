/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:43:46 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/13 19:48:20 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst1;
	char	*src1;
	char	*dst2;

	if (n == 0)
		return (dst);
	dst1 = (char*)dst;
	src1 = (char*)src;
	dst2 = (char*)dst;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	dst = (void*)dst1;
	return (dst2);
}
