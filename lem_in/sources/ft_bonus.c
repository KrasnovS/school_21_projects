/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:37:31 by lfarlen           #+#    #+#             */
/*   Updated: 2019/09/23 20:10:46 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_room(t_env env)
{
	t_room *tmp;
	t_link *tmp2;

	tmp = env.start;
	while (tmp)
	{
		ft_putstr("Room ");
		ft_putcolorendl(tmp->name, LIGHT_BLUE);
		tmp2 = tmp->connection;
		while (tmp2)
		{
			ft_putstr(" - link with ");
			ft_putcolorendl(tmp2->room->name, LIGHT_RED);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void	ft_print_path(t_env env)
{
	t_room	*tmp;
	int		i;

	i = 0;
	ft_putstr("\n---------\n");
	while (env.paths && env.paths[i])
	{
		ft_putstr("path ");
		ft_putnbrendl(i);
		ft_putstr("- ");
		tmp = env.paths[i];
		while (tmp->next)
		{
			ft_putstr(tmp->name);
			ft_putstr("->");
			tmp = tmp->next;
		}
		ft_putendl(tmp->name);
		i++;
	}
	ft_putstr("---------\n\n");
}
