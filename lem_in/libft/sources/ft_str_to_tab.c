/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 22:00:15 by lfarlen           #+#    #+#             */
/*   Updated: 2019/01/25 19:48:19 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		size_nw(const char *str, int i)
{
	while (str[i] && (ft_isspace(str[i]) == 0))
		i++;
	return (i);
}

void	norme(int i_y_x[3], char **tab, const char *str)
{
	while (str[i_y_x[0]] && ft_isspace(str[i_y_x[0]]) == 0)
	{
		tab[i_y_x[1]][i_y_x[2]] = str[i_y_x[0]];
		i_y_x[0]++;
		i_y_x[2]++;
	}
	tab[i_y_x[1]][i_y_x[2]] = '\0';
	i_y_x[1]++;
}

char	**ft_str_to_tab(char const *str)
{
	char	**tab;
	int		i_y_x[3];

	tab = NULL;
	i_y_x[0] = 0;
	i_y_x[1] = 0;
	if (!str)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_words(str) + 1));
	while (str[i_y_x[0]])
	{
		i_y_x[2] = 0;
		while (str[i_y_x[0]] && ft_isspace(str[i_y_x[0]]) == 1)
			i_y_x[0]++;
		if (str[i_y_x[0]])
		{
			tab[i_y_x[1]] = malloc(sizeof(char) * size_nw(str, i_y_x[0]) + 1);
			norme(i_y_x, tab, str);
		}
	}
	tab[i_y_x[1]] = NULL;
	return (tab);
}
