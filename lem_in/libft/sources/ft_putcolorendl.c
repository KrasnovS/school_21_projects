/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolorendl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:20:34 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/15 21:41:24 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putcolorendl(char *s, char *color)
{
	ft_putchar('\0');
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr(DEFAULT);
	ft_putchar('\n');
}
