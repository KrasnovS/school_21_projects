/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:50:52 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/02 14:52:59 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	q;
	size_t	res;

	i = 0;
	while (dst[i] != '\0')
		++i;
	res = 0;
	while (src[res] != '\0')
		++res;
	if (size <= i)
		res += size;
	else
		res += i;
	q = 0;
	while (src[q] != '\0' && i + 1 < size)
	{
		dst[i] = src[q];
		i++;
		q++;
	}
	dst[i] = '\0';
	return (res);
}
