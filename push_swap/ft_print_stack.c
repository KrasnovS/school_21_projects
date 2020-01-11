/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:10:21 by prawney           #+#    #+#             */
/*   Updated: 2019/08/17 15:00:46 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	printf("Stack A, len = %d\n", stack_a->len);
	while (i < stack_a->len)
	{
		printf("%d ", stack_a->stack[i]);
		i++;
	}
	i = 0;
	printf("\n");
	printf("Stack B, len = %d\n", stack_b->len);
	if (stack_b->len > 0)
	{
		while (i < stack_b->len)
		{
			printf("%d ", stack_b->stack[i]);
			i++;
		}
		printf("\n");
	}
}
