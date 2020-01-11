/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlldel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:57:32 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 15:34:23 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlldel(t_dllist **alst, void (*del)(void*, size_t))
{
	t_dllist	*left;
	t_dllist	*right;

	if (!alst || !*alst || !del)
		return ;
	right = alst[0]->right;
	left = alst[0]->left;
	ft_dlldeltoright(&right, del);
	ft_dlldeltoright(&right, del);
	ft_dlldelone(alst, del);
	alst = NULL;
}
