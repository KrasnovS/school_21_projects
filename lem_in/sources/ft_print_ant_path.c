/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ant_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:38:00 by lfarlen           #+#    #+#             */
/*   Updated: 2019/09/23 20:10:37 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_ant(int nb, t_room *room)
{
	if (room->end)
	{
		ft_putcolor("L", LIGHT_RED);
		ft_putnbrcolor(nb, LIGHT_RED);
		ft_putcolor("-", LIGHT_RED);
		ft_putcolor(room->name, LIGHT_RED);
	}
	else
	{
		ft_putchar('L');
		ft_putnbr(nb);
		ft_putchar('-');
		ft_putstr(room->name);
	}
	ft_putchar(' ');
}

static void	ft_rec_move_path(t_env *e, int i_ant[2], t_room *tmp)
{
	if (!(tmp->next->end))
		ft_rec_move_path(e, i_ant, tmp->next);
	if (tmp->start == 1 && !(tmp->next->nb_ants) && e->nb_ants > 0)
	{
		ft_print_ant(i_ant[1], tmp->next);
		tmp->next->ant_name = i_ant[1];
		tmp->next->nb_ants++;
		e->nb_ants--;
		(i_ant[1])++;
	}
	else if (tmp->nb_ants && !(tmp->next->nb_ants))
	{
		ft_print_ant(tmp->ant_name, tmp->next);
		tmp->next->ant_name = tmp->ant_name;
		tmp->nb_ants--;
		tmp->next->nb_ants++;
		if (tmp->next->end)
		{
			tmp->next->nb_ants = 0;
			e->arrive_ants++;
		}
	}
}

static void	ft_get_operations(t_env env)
{
	int i;

	i = 1;
	while (i <= env.nb_ants)
	{
		ft_putchar('L');
		ft_putnbr(i);
		ft_putchar('-');
		ft_putstr((env.paths[0])->next->name);
		if (i < env.nb_ants)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void		ft_moove_ants(t_env *env)
{
	t_room	**tmp;
	t_room	*tmp2;
	int		i_ant[2];
	int		nb_ants;

	nb_ants = env->nb_ants;
	env->arrive_ants = 0;
	i_ant[1] = 1;
	if (env->unique_path)
		return (ft_get_operations(*env));
	while (env->arrive_ants < nb_ants)
	{
		i_ant[0] = 0;
		tmp = env->paths;
		while (tmp[i_ant[0]])
		{
			tmp2 = tmp[i_ant[0]];
			ft_rec_move_path(env, i_ant, tmp2);
			i_ant[0]++;
		}
		ft_putchar('\n');
	}
}
