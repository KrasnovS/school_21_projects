/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:23:53 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/29 19:35:11 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtabadd(char ***tab, char *str)
{
	char	**tab2;
	int		i;

	i = -1;
	if (!str)
		return ;
	if (!*tab || !((*tab)[0]))
	{
		*tab = malloc(sizeof(char *) * 2);
		(*tab)[0] = ft_strdup(str);
		(*tab)[1] = NULL;
		return ;
	}
	tab2 = malloc(sizeof(char *) * (ft_get_size_tab((void**)*tab) + 2));
	while ((*tab)[++i])
		tab2[i] = ft_strdup((*tab)[i]);
	tab2[i++] = ft_strdup(str);
	tab2[i] = NULL;
	ft_free_double_pointer((void ***)tab);
	*tab = tab2;
}
