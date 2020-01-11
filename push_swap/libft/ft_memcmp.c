/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:31:13 by prawney           #+#    #+#             */
/*   Updated: 2018/12/18 21:07:09 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			i;

	s_1 = (unsigned char*)s1;
	s_2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s_1[i] != s_2[i])
			return ((int)(s_1[i] - s_2[i]));
		i++;
	}
	return (0);
}
