/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:50:49 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/20 22:24:21 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp_lst;

	while (*alst)
	{
		tmp_lst = *alst;
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(tmp_lst);
	}
	*alst = NULL;
}
