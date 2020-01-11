/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 21:44:23 by prawney           #+#    #+#             */
/*   Updated: 2019/08/17 17:02:19 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack, int rep)
{
	int index;
	int tmp;

	index = stack->len - 1;
	tmp = stack->stack[index];
	if (rep)
	{
		while (index > 0)
		{
			stack->stack[index] = stack->stack[index - 1];
			index--;
		}
		stack->stack[index] = tmp;
		reverse_rotate(stack, rep - 1);
	}
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, int rep)
{
	reverse_rotate(stack_a, rep);
	reverse_rotate(stack_b, rep);
}
