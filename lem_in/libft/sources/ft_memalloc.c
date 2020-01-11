/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:06:20 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/15 18:49:02 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*c;
	int				i;

	i = -1;
	c = NULL;
	c = (unsigned char *)malloc(size);
	if (c)
		while (size--)
			c[++i] = 0;
	return ((void *)c);
}
