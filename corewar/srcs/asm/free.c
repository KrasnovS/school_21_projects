/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:41:05 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/14 14:44:04 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		free_for_all(t_info *info)
{
	t_label_list	*tmp_lab;
	t_label_list	*lab_free;
	t_ins			*tmp_ins;
	t_ins			*ins_free;

	tmp_lab = info->labels;
	ft_free_string(&info->tmp);
	while (tmp_lab)
	{
		lab_free = tmp_lab;
		tmp_lab = tmp_lab->next;
		free(lab_free->name);
		free(lab_free);
	}
	tmp_ins = info->ins;
	while (tmp_ins)
	{
		ins_free = tmp_ins;
		tmp_ins = tmp_ins->next;
		free(ins_free->arg_1);
		free(ins_free->arg_2);
		free(ins_free->arg_3);
		free(ins_free);
	}
	return (-1);
}
