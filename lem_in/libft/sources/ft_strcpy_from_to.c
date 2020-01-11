/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_from_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:59:46 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/22 19:36:54 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_f_t(char *dest, const char *src, size_t from, size_t to)
{
	int i;

	i = 0;
	if (from > to)
		return (NULL);
	if (to > (ft_strlen(src) - 1))
		to = ft_strlen(src) - 1;
	while (src[from] && from <= to)
	{
		dest[i] = src[from];
		i++;
		from++;
	}
	dest[i] = '\0';
	return (dest);
}
