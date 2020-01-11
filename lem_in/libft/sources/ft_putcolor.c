/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:10:23 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/14 21:52:32 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putcolor(char *s, char *color)
{
	ft_putchar('\0');
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr(DEFAULT);
}
