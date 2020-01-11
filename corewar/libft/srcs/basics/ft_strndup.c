/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:24:46 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/11 21:22:39 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *s1, int n)
{
	char	*s2;
	int		i;
	int		j;

	j = 0;
	while (s1[j] && j < n)
		j++;
	if (!(s2 = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
