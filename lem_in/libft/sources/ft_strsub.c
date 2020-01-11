/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:13:01 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/19 21:01:14 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, size_t start, size_t len)
{
	unsigned	int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s && i < len && s[start])
	{
		if (!s[start])
			return (NULL);
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
