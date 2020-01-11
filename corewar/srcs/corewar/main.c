/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:00:48 by qhetting          #+#    #+#             */
/*   Updated: 2019/12/14 15:01:34 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "curses.h"

static int	error_msg(char error)
{
	if (error == 0)
		ft_putstr_fd("corewar: No arguments.\n", 2);
	if (error == 1)
		ft_putstr_fd("corewar: Invalid option.\n", 2);
	if (error == 2)
		ft_putstr_fd("corewar: Can't open file.\n", 2);
	if (error == 3)
		ft_putstr_fd("corewar: Can't read file.\n", 2);
	if (error == 4)
		ft_putstr_fd("corewar: Invalid champion input.\n", 2);
	if (error == 5)
		ft_putstr_fd("corewar: Malloc Error.\n", 2);
	if (error == 6)
		ft_putstr_fd("corewar: File does not begin with Magic Byte.\n", 2);
	if (error < 4)
	{
		write(2, "Usage : ./corewar player1.cor player2.cor\n", 42);
		write(2, "Available options :\n", 20);
		write(2, "    -n      [-n player_number player.cor]\n", 42);
		write(2, "  -dump     [-dump cycle], stops the game\n", 42);
		write(2, " -viewer    [-viewer], shows graphic mode\n", 42);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
		return (error_msg(0));
	if (parser(argv, &game) || init_game(&game))
		return (error_msg(game.error));
	if (game.viewer_mod)
		init_curses();
	corewar(&game);
	if (game.viewer_mod)
		endwin();
	game.dump ? print_map(&game) : print_result(&game);
	return (0);
}
