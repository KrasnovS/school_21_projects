/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlladdtoright.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:25:48 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 14:00:01 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddtoright(t_dllist **alst, t_dllist *new)
{
	if (!alst || !new || *alst)
		return ;
	new->left = *alst;
	alst[0]->right = new;
	*alst = new;
}
