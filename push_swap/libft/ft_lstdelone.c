/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:57:30 by prawney           #+#    #+#             */
/*   Updated: 2018/12/20 21:27:23 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (!alst || !alst[0] || !del)
		return ;
	if (alst[0] && alst[0]->content)
		del(alst[0]->content, alst[0]->content_size);
	free(alst[0]);
	alst[0] = NULL;
}
