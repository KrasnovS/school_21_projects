/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_byting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:39:31 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/13 21:25:16 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		reg_writing(t_info *info, long long *arg_n)
{
	print_n_bytes(info, arg_n[1], 1);
	return (0);
}

int		ind_writing(t_info *info, long long *arg_n)
{
	int		inv;

	if (arg_n[1] < 0)
	{
		inv = (arg_n[1] & 0xFFFF);
		print_n_bytes(info, inv, 2);
	}
	else
		print_n_bytes(info, arg_n[1], 2);
	return (0);
}

int		lab_writing(t_info *info, long long *arg_n, t_ins *ins)
{
	int	inv;
	int	two;

	two = ins->op_code <= 8 || ins->op_code == 13 \
		|| ins->op_code == 16 ? 2 : 0;
	if (arg_n[1] < 0)
	{
		inv = (two == 2 ? arg_n[1] & 0xFFFFFFFF : arg_n[1] & 0xFFFF);
		print_n_bytes(info, inv, two + 2);
	}
	else
		print_n_bytes(info, arg_n[1], two + 2);
	return (0);
}

int		dir_writing(t_info *info, long long *arg_n, t_ins *ins)
{
	if (ins->op_code >= 9 && ins->op_code <= 15 && ins->op_code != 13)
		print_n_bytes(info, arg_n[1], 2);
	else
		print_n_bytes(info, arg_n[1], 4);
	return (0);
}
