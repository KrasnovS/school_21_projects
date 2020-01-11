/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:34:52 by prawney           #+#    #+#             */
/*   Updated: 2018/12/20 22:41:14 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *src, t_list *dst)
{
	t_list	*tmp;
	t_list	*prev;

	if (!src)
		return (NULL);
	if (!(dst = ft_lstnew(src->content, src->content_size)))
		return (NULL);
	prev = dst;
	src = src->next;
	while (src)
	{
		if (!(tmp = ft_lstnew(src->content, src->content_size)))
		{
			ft_lstdel(&dst, &ft_lstfree);
			return (NULL);
		}
		prev->next = tmp;
		tmp = tmp->next;
		prev = prev->next;
		src = src->next;
	}
	return (dst);
}
