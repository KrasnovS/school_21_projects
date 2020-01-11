/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:39:01 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/03 20:48:40 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = (0);
	while (*s)
	{
		if (*s == c)
			last = (char*)s;
		++s;
	}
	if (last)
		return (last);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
