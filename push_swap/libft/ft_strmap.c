/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:46:33 by prawney           #+#    #+#             */
/*   Updated: 2018/12/19 20:13:12 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*map;

	if (s == NULL || f == NULL || !(len = ft_strlen(s)))
		return (NULL);
	i = 0;
	if (!(map = ft_strnew(len)))
		return (NULL);
	while (s[i] != '\0')
	{
		map[i] = f(s[i]);
		i++;
	}
	return (map);
}
