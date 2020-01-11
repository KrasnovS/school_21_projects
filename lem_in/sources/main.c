/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:38:27 by lfarlen           #+#    #+#             */
/*   Updated: 2019/09/23 20:10:35 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**ft_get_map(int ac, char *file_name, t_env *env)
{
	char **map;
	char **tmp;

	map = NULL;
	if (ac == 1)
		ft_get_stdin(&map);
	else
		ft_get_file(file_name, &map);
	if (!map || !map[0])
		return (NULL);
	env->original_map = ft_strtabdup((const char **)map);
	tmp = map;
	map = ft_strtabtrim(map);
	ft_free_double_pointer((void ***)&tmp);
	tmp = map;
	map = ft_get_data_comments(map);
	ft_free_double_pointer((void ***)&tmp);
	tmp = map;
	map = ft_get_data_commands(env, map);
	ft_free_double_pointer((void ***)&tmp);
	return (map);
}

void		ft_init_main(t_env *env)
{
	env->start = NULL;
	env->paths = NULL;
	env->print_path = 0;
	env->print_connection = 0;
	env->unique_path = 0;
}

void		ft_free_all(char ***map, t_env env, char ***map2)
{
	ft_free_double_pointer((void***)map);
	ft_free_double_pointer((void***)map2);
	ft_free_start(env.start);
	ft_free_paths(env.paths);
}

static int	ft_algoritm(t_env env, char **map)
{
	if (!ft_find_valid_paths(&env))
	{
		ft_free_all(&map, env, &(env.original_map));
		return (ft_error_msg("ERROR", 0));
	}
	ft_print_strtab(env.original_map);
	if (env.print_connection == 1)
		ft_print_room(env);
	ft_moove_ants(&env);
	if (env.print_path == 1)
		ft_print_path(env);
	ft_free_all(&map, env, &(env.original_map));
	return (0);
}

int			main(int ac, char **av)
{
	char	**map;
	t_env	env;

	ft_init_main(&env);
	if (ac > 2)
		return (ft_error_msg("ERROR", 0));
	if (!(map = ft_get_map(ac, av[1], &env)))
		return (ft_error_msg("ERROR", 0));
	if (!ft_parse_map(map, &env))
	{
		ft_free_all(&map, env, &(env.original_map));
		return (ft_error_msg("ERROR", 0));
	}
	if (!ft_dist_point(env))
	{
		ft_free_all(&map, env, &(env.original_map));
		return (0);
	}
	ft_algoritm(env, map);
	return (0);
}
