/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:13:01 by prawney           #+#    #+#             */
/*   Updated: 2018/12/19 21:01:14 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*s_sub;

	if (s != NULL)
		n = ft_strlen(s);
	else
		return (NULL);
	if ((len + start) > n)
		return (NULL);
	if (len == 0)
		return (ft_strnew(0));
	if (!(s_sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s_sub[len] = '\0';
	while (len > 0)
	{
		s_sub[len - 1] = (char)s[len - 1 + start];
		len--;
	}
	return (s_sub);
}
