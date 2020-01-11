/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:40:38 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/29 18:28:14 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	q;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		q = 0;
		while (i + q < len && s1[i + q] == s2[q] && s2[q] != '\0')
			q++;
		if (s2[q] == '\0')
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
