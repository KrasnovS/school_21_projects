/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlladdnextl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:15:48 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 19:00:01 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlladdnextl(t_dllist **alst, void const *content, \
	size_t content_size)
{
	t_dllist	*tmplst;
	t_dllist	*ptr;

	if (!alst)
		return (0);
	if (!(tmplst = ft_dllnew(content, content_size)))
		return (-1);
	if (*alst == NULL)
	{
		alst[0] = tmplst;
		return (1);
	}
	ptr = *alst;
	while (ptr->left != NULL)
		ptr = ptr->left;
	ptr->left = tmplst;
	tmplst->right = ptr;
	return (1);
}
