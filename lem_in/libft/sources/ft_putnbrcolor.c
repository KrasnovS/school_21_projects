/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:31:23 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/19 22:05:34 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbrcolor(int n, char *color)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		ft_putcolor("-", color);
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_putstr(color);
		ft_putchar(nb + '0');
		ft_putstr(DEFAULT);
	}
	if (nb > 9)
	{
		ft_putnbrcolor(nb / 10, color);
		ft_putstr(color);
		ft_putchar(nb % 10 + '0');
		ft_putstr(DEFAULT);
	}
}
