/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:17:31 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/29 19:49:49 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(const char **tab)
{
	char	**tab2;
	int		i;

	i = 0;
	tab2 = malloc(sizeof(char *) * (ft_get_size_tab((void **)tab) + 1));
	while (tab[i])
	{
		tab2[i] = ft_strdup(tab[i]);
		i++;
	}
	tab2[i] = NULL;
	return (tab2);
}
