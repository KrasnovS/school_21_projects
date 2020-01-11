/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 22:26:39 by prawney           #+#    #+#             */
/*   Updated: 2018/12/19 21:36:27 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_string(char **str, unsigned int num, int order, int i)
{
	if (num == 0)
	{
		str[0][0] = '0';
		return ;
	}
	while (order > 0)
	{
		str[0][order + i - 1] = (num % 10) + 48;
		num /= 10;
		order--;
	}
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	int				order;

	if (n < 0)
		num = (unsigned int)(-n);
	else
		num = (unsigned int)n;
	order = ft_order(num);
	if (n < 0)
		order++;
	if (!(str = ft_strnew(order)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		order--;
		n = 1;
	}
	else
		n = 0;
	set_string(&str, num, order, n);
	return (str);
}
