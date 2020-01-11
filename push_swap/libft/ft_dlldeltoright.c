/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlldeltoright.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:11:43 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 19:14:11 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlldeltoright(t_dllist **alst, void (*del)(void*, size_t))
{
	if (!alst || !*alst || !del)
		return ;
	ft_dlldeltoright(&alst[0]->right, del);
	ft_dlldelone(alst, del);
	alst = NULL;
}
