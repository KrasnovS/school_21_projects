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

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;
	int k;
	int s;

	if (!*to_find)
		return (char *)(str);
	i = 0;
	while (str[i] && len > 0)
	{
		if (len < ft_strlen(to_find))
			return (NULL);
		k = 0;
		s = i;
		while (str[s] == to_find[k] && to_find[k] && str[s])
		{
			k++;
			s++;
		}
		if (to_find[k] == '\0')
			return ((char *)str + i);
		len--;
		i++;
	}
	return (NULL);
}
