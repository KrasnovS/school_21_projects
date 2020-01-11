/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlldeltoleft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:45:43 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 20:32:45 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlldeltoleft(t_dllist **alst, void (*del)(void*, size_t))
{
	if (!alst || !*alst || !del)
		return ;
	ft_dlldeltoleft(&alst[0]->left, del);
	ft_dlldelone(alst, del);
	alst = NULL;
}
