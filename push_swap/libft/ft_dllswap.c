/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:11:15 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 21:45:23 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dllswap(t_dllist *a, t_dllist *b)
{
	void	*content;
	size_t	size;

	if (!a || !b)
		return ;
	content = a->content;
	a->content = b->content;
	b->content = content;
	if (a->content_size == b->content_size)
		return ;
	size = a->content_size;
	a->content_size = b->content_size;
	b->content_size = size;
}
