/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllcpyl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:27:37 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 17:48:08 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dllist	*ft_dllcpyl(t_dllist *src, t_dllist *dst)
{
	t_dllist	*tmp;
	t_dllist	*prev;

	if (!src)
		return (NULL);
	if (!(dst = ft_dllnew(src->content, src->content_size)))
		return (NULL);
	prev = dst;
	src = src->left;
	while (src)
	{
		if (!(tmp = ft_dllnew(src->content, src->content_size)))
		{
			ft_dlldel(&dst, &ft_lstfree);
			return (NULL);
		}
		prev->left = tmp;
		tmp->right = prev;
		tmp = tmp->left;
		prev = prev->left;
		src = src->left;
	}
	return (dst);
}
