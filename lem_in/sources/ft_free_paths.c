/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:37:51 by lfarlen           #+#    #+#             */
/*   Updated: 2019/09/23 20:10:42 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_paths(t_room **p)
{
	t_room	*r;
	int		i;

	i = 0;
	while (p[i])
	{
		while (p[i])
		{
			r = p[i]->next;
			free(p[i]->name);
			free(p[i]);
			p[i] = r;
		}
		i++;
	}
	free(p);
}

void		ft_free_start(t_room *r)
{
	t_room *tmp;
	t_link *co;
	t_link *co2;

	while (r)
	{
		tmp = r->next;
		co = r->connection;
		while (co)
		{
			co2 = co->next;
			free(co);
			co = co2;
		}
		free(r->name);
		free(r);
		r = tmp;
	}
}

void		ft_clear_path(t_room ***paths, int i)
{
	t_room *tmp;
	t_room *tmp2;

	tmp = (*paths)[i];
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp);
		tmp = NULL;
		tmp = tmp2;
	}
	(*paths)[i] = NULL;
}
