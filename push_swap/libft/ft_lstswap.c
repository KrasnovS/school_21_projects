/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:25:53 by prawney           #+#    #+#             */
/*   Updated: 2018/12/28 20:35:12 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *prev_a, t_list *a, t_list *prev_b, t_list *b)
{
	t_list	*tmp;

	if (!a || !b)
		return ;
	if (prev_a)
		prev_a->next = b;
	if (prev_b)
		prev_b->next = a;
	tmp = a->next;
	a->next = b->next;
	b->next = tmp;
}
