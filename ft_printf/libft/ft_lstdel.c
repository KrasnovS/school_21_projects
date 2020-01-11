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

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*row;
	t_list	*next;

	row = *alst;
	if (del != NULL)
	{
		while (row != NULL)
		{
			next = row->next;
			del(row->content, row->content_size);
			free(row);
			row = next;
		}
		*alst = NULL;
	}
}
