/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:06:23 by lfarlen           #+#    #+#             */
/*   Updated: 2019/05/04 20:21:06 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_on_fig(char *arr, t_figurka *tetri, int pos, int size)
{
	int		i;
	int		row;
	int		col;

	i = 3;
	if (pos >= (size * size))
		return (0);
	if (ft_search(arr, tetri->bukva) == 1)
		return (0);
	while (i != -1)
	{
		col = pos % size + (tetri->tochka[i]).col;
		row = pos / size + (tetri->tochka[i]).row;
		if ((col >= size) || (row >= size))
			return (0);
		if (ft_point(arr, col, row, size) == 1)
			i--;
		else
			return (0);
	}
	return (1);
}

int			ft_check(char *arr, t_figurka **list)
{
	int		i;

	i = 0;
	while (list[i] != 0)
	{
		if (ft_search(arr, list[i]->bukva) == 0)
			return (0);
		i++;
	}
	return (1);
}

int			ft_place_fig(t_figurka **list, t_solver *rec, int pos, int i)
{
	if (ft_check(rec->table, list) == 1)
		return (1);
	if (list[i] == 0)
		return (0);
	while (pos < rec->size * rec->size)
	{
		if (ft_on_fig(rec->table, list[i], pos, rec->size))
		{
			on_fig(rec->table, list[i], pos, rec->size);
			if (ft_place_fig(list, rec, 0, i + 1))
				return (1);
			off_fig(rec->table, list[i]);
		}
		pos++;
	}
	return (0);
}

int			ft_resolver(t_figurka **list, t_solver *rec)
{
	int		i;

	i = 0;
	while (i < rec->size * rec->size)
		(rec->table)[i++] = '.';
	(rec->table)[i] = '\0';
	return (ft_place_fig(list, rec, 0, 0));
}

void		ft_solver(t_figurka **list)
{
	t_solver	*rec;
	char		*arr;
	int			size;

	size = ft_map_size(ft_lstlen(list) * 4);
	if (!(rec = (t_solver *)ft_memalloc(sizeof(t_solver))))
		return ;
	if (!(arr = (char *)ft_memalloc(sizeof(*arr) * (17 * 28))))
		return ;
	rec->table = arr;
	rec->size = size;
	while ((ft_resolver(list, rec) == 0) && (rec->size < 25))
		rec->size++;
	ft_print_map(rec->table, rec->size);
	ft_memdel((void *)(&rec));
	ft_memdel((void *)(&arr));
}
