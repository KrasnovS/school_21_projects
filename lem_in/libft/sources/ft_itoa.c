/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 22:26:39 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/19 21:36:27 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define DECL_INIT int i; int neg; char *str; neg = 0
#define NBR_NEGATIF neg = 1; nbr = -nbr

static	int	malloc_size(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int nbr)
{
	DECL_INIT;
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr == I_MIN)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
	{
		NBR_NEGATIF;
	}
	i = malloc_size(nbr);
	if (!(str = malloc(sizeof(char) * (i + neg) + 1)))
		return (NULL);
	str[i + neg] = '\0';
	while (nbr > 0)
	{
		if (neg == 0)
			str[i - 1] = nbr % 10 + '0';
		if (neg == 1)
			str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
