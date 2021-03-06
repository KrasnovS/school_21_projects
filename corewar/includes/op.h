/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:56:30 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/14 15:20:41 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

/*
** size
*/

# define OP_SIZE				1

# define T_REG_SIZE				1
# define T_IND_SIZE				2

# define REG_SIZE				4

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define ALT_COMMENT_CHAR		';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

/*
** argument
*/

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
# define T_IND_LAB				16

/*
** champion
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

/*
** operations
*/

typedef struct		s_op
{
	char		name[PROG_NAME_LENGTH];
	int			nb_params;
	t_arg_type	params_type[3];
	int			op_code;
	int			cycles;
}					t_op;

extern t_op			g_op_tab[17];

#endif
