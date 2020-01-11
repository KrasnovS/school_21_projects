/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:51:53 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/03 21:21:49 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *need)
{
	unsigned int	i;
	unsigned int	q;

	i = 0;
	if (hay[0] == '\0' && need[0] == '\0')
		return ((char*)hay);
	while (hay[i] != '\0')
	{
		q = 0;
		while (need[q] != '\0' && hay[i + q] == need[q])
			q++;
		if (need[q] == '\0')
			return ((char*)hay + i);
		i++;
	}
	return (NULL);
}
