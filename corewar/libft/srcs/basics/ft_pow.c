/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 22:20:21 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/13 19:53:08 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_pow(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_pow(nb, power - 1));
}
