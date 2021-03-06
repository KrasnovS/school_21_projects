/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:11:46 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/13 20:10:39 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_dpow(long double nb, int pow)
{
	if (pow == 0)
		return (1);
	if (pow < 0)
		return (0);
	return (nb * ft_dpow(nb, pow - 1));
}
