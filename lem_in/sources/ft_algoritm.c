/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:39:37 by lfarlen           #+#    #+#             */
/*   Updated: 2019/09/23 20:10:49 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_create_path(t_env *env)
{
	t_room *r;

	r = env->start;
	env->paths = malloc(sizeof(t_room *) * 2);
	(env->paths)[0] = ft_create_link_room(r->name, r->start, r->end, r->coord);
	while (r->end != 1)
		r = r->next;
	((env->paths)[0])->next =
	ft_create_link_room(r->name, r->start, r->end, r->coord);
	((env->paths)[1]) = NULL;
	env->unique_path = 1;
}

static int	ft_find_valid_paths2(int i[3], t_env *env, t_room **tmp)
{
	i[2] = -2;
	i[0] = -1;
	if ((i[1] = ft_max_path(env)) == -1)
	{
		ft_create_path(env);
		return (1);
	}
	env->paths = malloc(sizeof(t_room *) * (i[1] + 1));
	while (++i[0] < i[1] + 1)
		(env->paths)[i[0]] = NULL;
	(*tmp) = env->start;
	while ((*tmp) && !(*tmp)->start)
		(*tmp) = (*tmp)->next;
	return (0);
}

int			ft_find_valid_paths(t_env *env)
{
	int		i[3];
	t_room	*tmp;
	t_link	*tmp2;

	tmp = NULL;
	if (ft_find_valid_paths2(i, env, &tmp) == 1)
		return (1);
	tmp2 = tmp->connection;
	if (!tmp)
		return (0);
	while (tmp2)
	{
		if (tmp2->room->dist_point > i[2])
			i[2] = tmp2->room->dist_point;
		tmp2 = tmp2->next;
	}
	if (i[2] < 0)
		return (0);
	ft_find_small_path(tmp, env);
	return (1);
}

void		ft_find_dist_point(t_room *tmp, int dist)
{
	t_link *link;

	link = tmp->connection;
	while (link)
	{
		if (link->room->dist_point == -2 || link->room->dist_point > dist)
		{
			link->room->dist_point = dist;
			ft_find_dist_point(link->room, dist + 1);
		}
		link = link->next;
	}
}

int			ft_dist_point(t_env env)
{
	int		dist;
	t_room	*tmp;

	dist = 1;
	tmp = env.start;
	while (tmp && !tmp->end)
		tmp = tmp->next;
	if (!tmp)
		return (0);
	ft_find_dist_point(tmp, dist);
	return (1);
}
