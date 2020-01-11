/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:06:33 by lfarlen           #+#    #+#             */
/*   Updated: 2019/05/04 22:25:04 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_write_on(char *table, char letter, int index)
{
	table[index] = letter;
}

void		on_fig(char *table, t_figurka *tetri, int pos, int size)
{
	int		i;
	int		row;
	int		col;

	i = 0;
	while (i != 4)
	{
		col = pos % size + (tetri->tochka[i]).col;
		row = pos / size + (tetri->tochka[i]).row;
		ft_write_on(table, tetri->bukva, row * size + col);
		i++;
	}
}

void		off_fig(char *table, t_figurka *tetri)
{
	int		i;

	i = 0;
	while (table[i])
	{
		if (table[i] == tetri->bukva)
			table[i] = '.';
		i++;
	}
}
