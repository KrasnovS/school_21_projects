/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:39:49 by lfarlen           #+#    #+#             */
/*   Updated: 2019/09/23 20:10:54 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_add_room(int i, t_room *r, t_room ***paths)
{
	t_room *tmp;

	if (!(*paths)[i])
	{
		(*paths)[i] = ft_create_link_room(r->name, r->start, r->end, r->coord);
	}
	else
	{
		tmp = (*paths)[i];
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_link_room(r->name, r->start, r->end, r->coord);
	}
	if (!(r->start) && !(r->end))
		r->dist_point = -5;
}
