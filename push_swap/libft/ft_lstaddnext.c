/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:36:01 by prawney           #+#    #+#             */
/*   Updated: 2018/12/20 22:15:12 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstaddnext(t_list **alst, void const *content, size_t content_size)
{
	t_list	*tmplst;
	t_list	*l_ptr;

	if (!alst)
		return (0);
	if (!(tmplst = ft_lstnew(content, content_size)))
		return (-1);
	if (alst[0] == NULL)
	{
		alst[0] = tmplst;
		return (1);
	}
	l_ptr = alst[0];
	while (l_ptr->next != NULL)
		l_ptr = l_ptr->next;
	l_ptr->next = tmplst;
	return (1);
}
