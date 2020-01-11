/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlladdtoleft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:11:48 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 19:23:04 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddtoleft(t_dllist **alst, t_dllist *new)
{
	if (!alst || !new || *alst)
		return ;
	new->right = *alst;
	alst[0]->left = new;
	*alst = new;
}
