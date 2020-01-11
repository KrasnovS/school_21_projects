/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:51:53 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/11 21:24:01 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;
	int len;

	i = 0;
	len = ft_strlen((char *)needle);
	if (len == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		k = i;
		while ((needle[j]) && (haystack[i]) && (needle[j] == haystack[i]))
		{
			i++;
			j++;
		}
		if (j == len)
			return ((char*)(haystack + i - len));
		i = k + 1;
	}
	return (NULL);
}
