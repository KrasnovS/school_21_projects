/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:03:21 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/18 21:26:55 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *w, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char*)w;
	while (n-- > 0)
		*(src++) = (unsigned char)c;
	return (w);
}
