/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinmulti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:22:16 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/13 20:00:35 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdarg.h>

char		*ft_strjoinmulti(int nb, ...)
{
	va_list	ap;
	char	**tab;
	char	*tmp;
	char	*res;
	int		i;

	if (nb < 2 || !(tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	va_start(ap, nb);
	i = -1;
	while (++i < nb)
		tab[i] = va_arg(ap, char *);
	tab[i] = NULL;
	va_end(ap);
	i = 0;
	res = ft_strdup(tab[0]);
	while (tab[++i])
	{
		tmp = ft_strjoin(res, tab[i]);
		free(res);
		res = tmp;
	}
	free(tab);
	return (res);
}
