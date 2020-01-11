/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:18:50 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/28 18:38:13 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;
	void	*cp_content;

	cp_content = (void*)ft_memalloc(content_size);
	if (!cp_content)
		return (NULL);
	if (content == NULL)
	{
		cp_content = NULL;
		content_size = 0;
	}
	else
		cp_content = ft_memcpy(cp_content, content, content_size);
	new_list = (t_list*)malloc(sizeof(new_list) * content_size);
	if (!new_list)
		return (NULL);
	new_list->content = cp_content;
	new_list->content_size = content_size;
	new_list->next = NULL;
	return (new_list);
}
