/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 23:10:10 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/29 18:44:03 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*list;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((list = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list = f(lst);
	newlst = list;
	while (lst->next)
	{
		lst = lst->next;
		if ((list->next = (t_list*)malloc(sizeof(t_list))) == NULL)
		{
			ft_free_all(newlst);
			return (NULL);
		}
		if ((list->next = f(lst)) == NULL)
		{
			ft_free_all(newlst);
			return (NULL);
		}
		list = list->next;
	}
	return (newlst);
}
