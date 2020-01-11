/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:24:11 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/23 13:16:33 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_get_distance(t_point pos_char, t_point p1)
{
	double res;

	res = sqrt(pow(pos_char.x - p1.x, 2) + pow(pos_char.y - p1.y, 2));
	return (res);
}
