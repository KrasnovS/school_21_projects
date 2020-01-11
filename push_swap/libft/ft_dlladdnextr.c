/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlladdnextr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:15:48 by prawney             #+#    #+#           */
/*   Updated: 2019/06/24 17:00:01 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlladdnextr(t_dllist **alst, void const *content, \
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
	while (ptr->right != NULL)
		ptr = ptr->right;
	ptr->right = tmplst;
	tmplst->left = ptr;
	return (1);
}
