/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:39:08 by lfarlen           #+#    #+#             */
/*   Updated: 2019/09/23 20:10:38 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_get_room(char *line, t_env *env, int s, int e)
{
	char	**to_tab;
	t_room	*tmp;
	int		coord[2];

	tmp = env->start;
	to_tab = ft_str_to_tab(line);
	if (!ft_str_is_number(to_tab[1]) || !ft_str_is_number(to_tab[2]))
		return (0);
	if (!ft_valid_name(to_tab[0]))
		return (0);
	coord[0] = ft_atoi(to_tab[1]);
	coord[1] = ft_atoi(to_tab[2]);
	if (ft_check_name(to_tab[0], *env))
		return (0);
	if (!tmp)
		env->start = ft_create_link_room(to_tab[0], s, e, coord);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_link_room(to_tab[0], s, e, coord);
	}
	ft_free_double_pointer((void ***)&to_tab);
	return (1);
}

t_link		*ft_create_connect(t_room *room)
{
	t_link	*link;

	link = malloc(sizeof(t_link));
	link->room = room;
	link->next = NULL;
	return (link);
}

static int	ft_add_connect2(char *name2, t_room *tmp, t_room *tmp2)
{
	t_link	*link_tmp;
	t_link	*link_tmp2;

	if (!(link_tmp = tmp->connection))
		tmp->connection = ft_create_connect(tmp2);
	else
	{
		while (link_tmp->next)
		{
			if (!ft_strcmp(link_tmp->room->name, name2))
				return (0);
			link_tmp = link_tmp->next;
		}
		link_tmp->next = ft_create_connect(tmp2);
	}
	if (!(link_tmp2 = tmp2->connection))
		tmp2->connection = ft_create_connect(tmp);
	else
	{
		while (link_tmp2->next)
			link_tmp2 = link_tmp2->next;
		link_tmp2->next = ft_create_connect(tmp);
	}
	return (1);
}

int			ft_add_connect(t_env *env, char *name1, char *name2)
{
	t_room	*tmp;
	t_room	*tmp2;

	tmp = env->start;
	tmp2 = env->start;
	if (!ft_strcmp(name1, name2))
		return (0);
	if (!tmp)
		return (0);
	while (ft_strcmp(tmp->name, name1))
		tmp = tmp->next;
	while (ft_strcmp(tmp2->name, name2))
		tmp2 = tmp2->next;
	if (!tmp || !tmp2)
		return (0);
	if (ft_add_connect2(name2, tmp, tmp2) == 0)
		return (0);
	return (1);
}

int			ft_get_connect(char *line, t_env *env)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, '-');
	if (!tab || !tab[0] || !tab[1] || tab[2])
		return (0);
	if (!ft_check_name(tab[0], *env) ||
		!ft_check_name(tab[1], *env))
		return (0);
	if (ft_check_connect(tab[0], tab[1], *env))
	{
		ft_free_double_pointer((void ***)&tab);
		return (1);
	}
	if (!ft_add_connect(env, tab[0], tab[1]))
		return (0);
	ft_free_double_pointer((void ***)&tab);
	return (1);
}
