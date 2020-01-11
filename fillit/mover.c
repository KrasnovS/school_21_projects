/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:06:46 by lfarlen           #+#    #+#             */
/*   Updated: 2019/05/04 20:21:07 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_move(char *tetri)
{
	ft_move_v(tetri, 0);
	ft_move_h(tetri, 0);
}

void		ft_move_v(char *tetri, int k)
{
	int		i;
	int		j;

	i = -1;
	if (k == 3)
		return ;
	while (++i < 4)
	{
		if (tetri[i] != '.')
			break ;
	}
	if (i == 4)
	{
		j = 4;
		while (j != 4 * 4)
		{
			tetri[j - 4] = tetri[j];
			j++;
		}
		j = 4 * 4 - 4;
		while (j < 4 * 4)
			tetri[j++] = '.';
		ft_move_v(tetri, k + 1);
	}
	return ;
}

void		ft_move_h(char *tetri, int k)
{
	int		i;
	int		j;

	i = -1;
	if (k == 3)
		return ;
	while (++i < 4 * 4)
	{
		if ((i % 4 == 0) && (tetri[i] != '.'))
			break ;
	}
	if (i == 4 * 4)
	{
		j = 0;
		while (j != 4 * 4)
		{
			tetri[j] = tetri[j + 1];
			tetri[j + 1] = tetri[j + 2];
			tetri[j + 2] = tetri[j + 3];
			tetri[j + 3] = '.';
			j += 4;
		}
		ft_move_h(tetri, k + 1);
	}
	return ;
}
