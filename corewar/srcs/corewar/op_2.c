/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:19:22 by prawney           #+#    #+#             */
/*   Updated: 2019/12/14 15:03:35 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	op_xor(t_proc *proc, t_game *game)
{
	int jump;
	int val1;
	int val2;
	int reg;

	if (!coding_byte(game->arena[MODM(proc->pc + 1)], \
		game->op_tab[8].params_type, 0, &jump) && !(jump = 0))
	{
		proc->jump = 2;
		val1 = get_param(game, proc, \
			((game->arena[MODM(proc->pc + 1)]) >> 6) & 3, 0);
		val2 = get_param(game, proc, \
			((game->arena[MODM(proc->pc + 1)]) >> 4) & 3, 0);
		reg = game->arena[MODM(proc->pc + proc->jump)] - 1;
		if (reg >= 0 && reg <= REG_NUMBER - 1)
		{
			proc->reg[reg] = val1 ^ val2;
			proc->carry = val1 ^ val2 ? 0 : 1;
		}
		proc->jump++;
	}
	proc->pc = MODM(proc->pc + jump + proc->jump);
}

void	op_zjmp(t_proc *proc, t_game *game)
{
	int	idx;

	if (proc->carry == 1)
	{
		idx = MODI(get_short(game->arena, proc->pc + 1));
		proc->pc = MODM(proc->pc + idx);
	}
	else
		proc->pc = MODM(proc->pc + 3);
}

void	op_ldi(t_proc *proc, t_game *game)
{
	int jump;
	int	val1;
	int val2;
	int res;
	int reg;

	if (!coding_byte(game->arena[MODM(proc->pc + 1)], \
		game->op_tab[10].params_type, 0, &jump) && !(jump = 0))
	{
		proc->jump = 2;
		val1 = get_param(game, proc, \
			((game->arena[MODM(proc->pc + 1)]) >> 6) & 3, 1);
		val2 = get_param(game, proc, \
			((game->arena[MODM(proc->pc + 1)]) >> 4) & 3, 1);
		res = get_int(game->arena, MODM(proc->pc + MODI(val1 + val2)));
		reg = game->arena[MODM(proc->pc + proc->jump)] - 1;
		if (reg >= 0 && reg <= REG_NUMBER - 1)
			proc->reg[reg] = res;
		proc->jump++;
	}
	proc->pc = MODM(proc->pc + jump + proc->jump);
}

void	op_sti(t_proc *proc, t_game *game)
{
	int jump;
	int reg_val;
	int	idx1;
	int idx2;
	int i;

	i = -1;
	if (!coding_byte(game->arena[MODM(proc->pc + 1)], \
		game->op_tab[11].params_type, 0, &jump) && !(jump = 0))
	{
		proc->jump = 2;
		reg_val = get_param(game, proc, REG_CODE, 1);
		idx1 = get_param(game, proc, \
			((game->arena[MODM(proc->pc + 1)]) >> 4) & 3, 1);
		idx2 = get_param(game, proc, \
			((game->arena[MODM(proc->pc + 1)]) >> 2) & 3, 1);
		write_arena(game->arena, MODM(proc->pc + MODI(idx1 + idx2)), reg_val);
		while (++i < 4)
		{
			game->viewer.color[MODM(proc->pc \
					+ MODI(idx1 + idx2) + i)] = proc->id;
			game->viewer.bold[MODM(proc->pc + MODI(idx1 + idx2) + i)] = 100;
		}
	}
	proc->pc = MODM(proc->pc + jump + proc->jump);
}

void	op_fork(t_proc *proc, t_game *game)
{
	int	idx;

	idx = MODI(get_short(game->arena, MODM(proc->pc + 1)));
	dup_proc(proc, game, MODM(proc->pc + idx));
	proc->pc = MODM(proc->pc + 3);
}
