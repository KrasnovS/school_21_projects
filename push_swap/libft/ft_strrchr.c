/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:39:01 by prawney           #+#    #+#             */
/*   Updated: 2018/12/03 20:48:40 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*a;

	i = ft_strlen(s);
	a = (char*)s;
	while (i != 0)
	{
		if (s[i] == c)
			return (a + i);
		i--;
	}
	if (s[i] == c)
		return (a + i);
	return (0);
}
