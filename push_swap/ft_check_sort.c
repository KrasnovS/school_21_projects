/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:18:21 by prawney           #+#    #+#             */
/*   Updated: 2019/08/17 15:09:33 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	index = 0;
	if (stack_b->len != 0)
		return (0);
	if (stack_a->len == 1)
		return (1);
	while (index <= stack_a->len - 2 &&
	stack_a->stack[index] < stack_a->stack[index + 1])
		index++;
	return (stack_a->len - index);
}
