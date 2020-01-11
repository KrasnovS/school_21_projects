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

int	ft_atoi(const char *str)
{
	long long		res;
	long long		rescheck;
	unsigned int	i;
	int				minus;

	res = 0;
	minus = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\v' || str[i] == '\r' ||
					str[i] == '\t' || str[i] == '\n' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rescheck = res;
		res = res * 10 + (str[i++] - 48);
		if (rescheck > res)
			return ((minus < 0) ? 0 : -1);
	}
	return ((int)res * minus);
}
