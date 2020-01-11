/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:42:44 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/29 18:56:20 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_free_double_pointer(void ***pointer)
{
	int i;

	i = 0;
	if (!*pointer)
		return ;
	while ((*pointer)[i])
	{
		free((*pointer)[i]);
		(*pointer)[i] = NULL;
		i++;
	}
	free(*pointer);
	*pointer = NULL;
}
