/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figurki.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:06:55 by lfarlen           #+#    #+#             */
/*   Updated: 2019/05/04 22:16:19 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figurka			*tmp_fig(char *str)
{
	t_figurka		*tetri;
	t_position		*point;
	int				i;
	int				j;

	i = -1;
	j = 0;
	if (!(tetri = (t_figurka *)ft_memalloc(sizeof(*tetri))) \
		|| !(tetri->tochka = (t_position *)ft_memalloc(sizeof(*point) * 5)))
		return (NULL);
	while (str[++i])
	{
		if (str[i] != '.')
		{
			(tetri->tochka)[j].row = i / 4;
			(tetri->tochka)[j++].col = i % 4;
			tetri->bukva = str[i];
		}
	}
	if (j != 4 || !(ft_points((tetri->tochka))))
	{
		ft_memdel((void **)(&tetri->tochka));
		ft_memdel((void **)(&tetri));
	}
	return (tetri);
}

int					ft_get_next_fig(char *list, char *buf, char c, size_t *k)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (list[j] && i != 16)
	{
		if (list[j] == '\n')
			j++;
		buf[i] = (list[j] == '#') ? c : list[j];
		i++;
		j++;
	}
	buf[i] = '\0';
	ft_move(buf);
	*k = *k + j - 1;
	return (1);
}

t_figurka			*ft_get_fig(char *list, size_t *tmp_i, char *tmp, size_t k)
{
	t_figurka		*tetri;

	tetri = NULL;
	if (ft_get_next_fig(list + *tmp_i, tmp, 'A' + k, tmp_i) \
						&& !(tetri = tmp_fig(tmp)))
	{
		ft_memdel((void **)(&tmp));
		return (NULL);
	}
	ft_memdel((void **)(&tmp));
	return (tetri);
}

int					ft_figurki(char *list, t_figurka ***tmp_list_tetri)
{
	t_figurka		*tetri;
	char			*tmp_list;
	size_t			i;
	size_t			j;

	i = -1;
	j = 0;
	while (list[++i])
	{
		if ((list[i + 1] && list[i] != '\n') && (list[i + 1] != '\n'))
		{
			if (!(tmp_list = (char *)ft_memalloc(sizeof(*tmp_list) \
							* (ft_strlen(list) + 1))))
				return (0);
			if ((tetri = ft_get_fig(list, &i, tmp_list, j)))
				(*tmp_list_tetri)[j++] = tetri;
			else
			{
				return (0);
			}
		}
	}
	(*tmp_list_tetri)[j] = 0;
	return (1);
}
