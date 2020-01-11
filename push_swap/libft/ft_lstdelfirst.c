/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:59:11 by prawney           #+#    #+#             */
/*   Updated: 2018/12/20 22:23:45 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmplst;

	if (!alst || !*alst || !del)
		return ;
	tmplst = alst[0]->next;
	ft_lstdelone(alst, del);
	*alst = tmplst;
}
