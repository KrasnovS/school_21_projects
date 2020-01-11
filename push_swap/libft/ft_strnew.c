/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:35:56 by prawney           #+#    #+#             */
/*   Updated: 2018/12/26 23:09:11 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*area;

	if ((size + 1) == 0)
		return (NULL);
	if (!(area = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size++;
	while (size > 0)
	{
		area[size - 1] = '\0';
		size--;
	}
	return (area);
}
