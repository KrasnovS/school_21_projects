/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:08:01 by lfarlen           #+#    #+#             */
/*   Updated: 2019/04/30 21:58:14 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	void	*i;

	i = malloc(size);
	if (i == NULL)
		return (NULL);
	i = ft_memset(i, 0, size);
	return (i);
}
