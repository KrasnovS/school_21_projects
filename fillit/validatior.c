/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatior.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:07:40 by lfarlen           #+#    #+#             */
/*   Updated: 2019/05/04 20:21:09 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_on_map(t_position p1, t_position p2)
{
	if (((p1.col - p2.col) == 1) && ((p1.row - p2.row) == 0))
		return (1);
	if (((p1.col - p2.col) == 0) && ((p1.row - p2.row) == 1))
		return (1);
	if (((p1.col - p2.col) == -1) && ((p1.row - p2.row) == 0))
		return (1);
	if (((p1.col - p2.col) == 0) && ((p1.row - p2.row) == -1))
		return (1);
	return (0);
}

int			ft_points(t_position *point)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (ft_on_map(point[i], point[j]))
			{
				count++;
				if (count >= 6)
					return (1);
			}
		}
	}
	return (0);
}

int			ft_valid_fig(char *buf)
{
	size_t	i;
	size_t	j;

	if ((buf[0] != '.') && (buf[0] != '#'))
		return (0);
	i = -1;
	while (buf[++i])
	{
		j = -1;
		while (++j < 20)
		{
			if ((j + 1) % 5 == 0 && (buf[j + i] != '\n'))
				return (0);
			if ((j + 1) % 5 != 0)
			{
				if ((buf[j + i] != '.') && (buf[j + i] != '#'))
					return (0);
			}
		}
		i += j;
		if (buf[i] == 0 || buf[i] != '\n')
			return (buf[i] == 0 ? 1 : 0);
	}
	return (0);
}
