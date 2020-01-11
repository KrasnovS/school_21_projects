/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:05:52 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/18 21:08:21 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*row;

	i = 0;
	row = (unsigned char*)s;
	while (++i <= n)
		if (*(row++) == (unsigned char)c)
			return ((void*)--row);
	return (0);
}
