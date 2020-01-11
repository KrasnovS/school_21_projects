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

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (f(lst));
	tmp = ft_lstmap(lst->next, f);
	ft_lstadd(&tmp, f(lst));
	return (tmp);
}
