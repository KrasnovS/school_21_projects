/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:07:49 by lfarlen           #+#    #+#             */
/*   Updated: 2019/05/04 21:52:19 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_usage(void)
{
	write(1, "usage: fillit input_file\n", 25);
	exit(0);
}

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void		free_list(t_figurka **list_tetri)
{
	int	i;

	if (list_tetri == NULL)
		return ;
	i = 0;
	while (list_tetri[i])
	{
		ft_memdel((void **)(&(list_tetri[i])->tochka));
		ft_memdel((void **)(&(list_tetri[i])));
		i++;
	}
	ft_memdel((void **)(&list_tetri));
}

int			main(int argc, char **argv)
{
	t_figurka	**tetri;
	char		*buf;
	int			fd;

	tetri = NULL;
	if (!(tetri = (t_figurka **)ft_memalloc(sizeof(t_figurka *) * 27)))
		return (0);
	if (argc != 2)
		ft_usage();
	if ((open(argv[1], O_RDONLY)) == -1)
		ft_error();
	if ((fd = open(argv[1], O_RDONLY)) != -1)
	{
		if (!(buf = (char *)ft_memalloc(sizeof(char *) * (26 * BUFF_SIZE))))
			return (0);
		read(fd, buf, 26 * BUFF_SIZE);
		if (ft_valid_fig(buf) == 1 && ft_figurki(buf, &tetri) == 1)
			ft_solver(tetri);
		else
			ft_error();
		ft_memdel((void **)(&buf));
		close(fd);
	}
	free_list(tetri);
	return (0);
}
