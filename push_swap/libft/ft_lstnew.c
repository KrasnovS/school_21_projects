/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:18:50 by prawney           #+#    #+#             */
/*   Updated: 2018/12/28 18:38:13 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if (!(new_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size)
	{
		if (!(new_list->content = (void*)malloc(content_size)))
		{
			free(new_list);
			return (NULL);
		}
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
		new_list->next = NULL;
	}
	else
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		new_list->next = NULL;
	}
	return (new_list);
}
