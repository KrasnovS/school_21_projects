/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:07:29 by lfarlen           #+#    #+#             */
/*   Updated: 2019/05/04 22:07:01 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_point(char *table, int col, int row, int size)
{
	if (table[row * size + col] != '.')
		return (0);
	return (1);
}

int			ft_search(char *table, char c)
{
	int		i;

	i = 0;
	while (table[i])
	{
		if (table[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t		ft_lstlen(t_figurka **list_tetri)
{
	size_t	list_len;

	list_len = 0;
	while (list_tetri[list_len] != 0)
		list_len++;
	return (list_len);
}

int			ft_map_size(int n)
{
	int		i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

void		ft_print_map(char *table, int size)
{
	int		i;

	i = 0;
	while (i < size * size)
	{
		if ((i % size == 0) && (i != 0))
			write(1, "\n", 1);
		write(1, &table[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
