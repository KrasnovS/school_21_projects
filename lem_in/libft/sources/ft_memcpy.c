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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*str_dest;
	unsigned char	*str_src;

	i = 0;
	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (str_dest);
}
