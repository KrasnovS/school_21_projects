/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:41:05 by prawney           #+#    #+#             */
/*   Updated: 2018/12/19 22:09:17 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == 10)
	{
		ft_putchar(49);
		n = 0;
	}
	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		ft_putchar('8');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
}
