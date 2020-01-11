/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:48:41 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/13 19:54:46 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_sortarr(int **numbers, int len)
{
	int		i;
	int		j;
	int		buff;

	i = -1;
	while (++i < len && ((j = i) + 1))
		while (++j < len)
			if ((*numbers)[i] > (*numbers)[j])
			{
				buff = (*numbers)[i];
				(*numbers)[i] = (*numbers)[j];
				(*numbers)[j] = buff;
			}
}
