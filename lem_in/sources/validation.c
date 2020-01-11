/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:37:45 by lfarlen           #+#    #+#             */
/*   Updated: 2019/09/23 20:10:33 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_valid_line(char *str)
{
	char	**test;
	int		i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] == '#')
		return (1);
	if (!(test = ft_str_to_tab(str)) || !test[0])
	{
		ft_free_double_pointer((void ***)&test);
		return (0);
	}
	ft_free_double_pointer((void ***)&test);
	return (1);
}

static void	ft_get_data(t_env *e, char **input, int i[3], char **str)
{
	if (!ft_strcmp(input[i[0]], "##connect"))
		e->print_connection = 1;
	if (!ft_strcmp(input[i[0]], "##path"))
		e->print_path = 1;
	if (input[i[0]][0] != '#' || !ft_strcmp(input[i[0]], "##start") ||
		!ft_strcmp(input[i[0]], "##end"))
	{
		str[i[1]] = ft_strdup(input[i[0]]);
		i[1]++;
	}
}

char		**ft_get_data_commands(t_env *e, char **input)
{
	int		i[3];
	char	**str;

	i[2] = ft_get_size_tab((void **)(input));
	i[1] = 0;
	i[0] = -1;
	while ((input)[++i[0]] != NULL)
	{
		if ((input)[i[0]][0] == '#' && ft_strcmp(input[i[0]], "##start") &&
		ft_strcmp(input[i[0]], "##end"))
			i[1]++;
	}
	str = malloc(sizeof(char *) * (i[2] - i[1] + 1));
	i[0] = -1;
	i[1] = 0;
	while (input[++i[0]] && ft_valid_line(input[i[0]]))
		ft_get_data(e, input, i, str);
	str[i[1]] = NULL;
	return (str);
}

char		**ft_get_data_comments(char **input)
{
	int		i[3];
	char	**str;

	i[2] = ft_get_size_tab((void **)(input));
	i[1] = 0;
	i[0] = -1;
	while ((input)[++i[0]] != NULL)
	{
		if ((input)[i[0]][0] == '#' && (input)[i[0]][0] != '#')
			i[1]++;
	}
	str = malloc(sizeof(char *) * (i[2] - i[1] + 1));
	i[0] = -1;
	i[1] = 0;
	while ((input)[++i[0]])
	{
		if ((input)[i[0]][0] != '#' || (input)[i[0]][1] == '#')
		{
			str[i[1]] = ft_strdup((input)[i[0]]);
			i[1]++;
		}
	}
	str[i[1]] = NULL;
	return (str);
}
