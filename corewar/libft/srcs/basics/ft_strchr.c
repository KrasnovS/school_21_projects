/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:54:47 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/11 21:20:04 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(char const *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	while (s[i] != c && s[i])
		i++;
	if (i == len && c != '\0')
		return (NULL);
	return ((char *)s + i);
}
