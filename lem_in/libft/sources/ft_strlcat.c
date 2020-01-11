/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:50:52 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/02 15:59:45 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	de;

	i = 0;
	while (dest[i] && i < size)
		i++;
	de = i;
	while (src[i - de] && i < size - 1)
	{
		dest[i] = src[i - de];
		i++;
	}
	if (de < size)
		dest[i] = '\0';
	return (de + ft_strlen(src));
}
