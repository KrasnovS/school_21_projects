/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:56:33 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/24 20:20:58 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabtrim(char **input)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_get_size_tab((void **)input) + 1));
	while (input[i])
	{
		tab[i] = ft_strtrim(input[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
