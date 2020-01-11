/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:17:46 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/19 20:43:50 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INIT result = 0; sign = 1; cpt = 0

int		ft_atoi(const char *str)
{
	int			result;
	int			sign;
	int			cpt;

	INIT;
	while (str[cpt] == ' ' || str[cpt] == '\n' || str[cpt] == '\t' ||
			str[cpt] == '\f' || str[cpt] == '\v' || str[cpt] == '\r')
		cpt++;
	sign = (str[cpt] == '-') ? -1 : 1;
	if (str[cpt] == '-')
		cpt++;
	else if (str[cpt] == '+')
		cpt++;
	while (str[cpt] == '0')
		cpt++;
	while (str[cpt] != '\0' && str[cpt] <= '9' && str[cpt] >= '0')
	{
		result = result * 10 + str[cpt] - '0';
		cpt++;
	}
	if (result == I_MAX)
		return (I_MAX);
	if (result == I_MIN)
		return (I_MIN);
	return (result * sign);
}
