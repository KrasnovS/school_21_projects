/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:41:54 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/29 15:42:30 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_file(char *av, char ***map)
{
	int		fd;
	int		nb_return;
	int		i;
	char	*line;

	i = 0;
	nb_return = 0;
	if ((fd = open(av, O_RDWR)) < 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		nb_return++;
	}
	ft_strdel(&line);
	close(fd);
	if (!(*map = (char**)malloc(sizeof(char*) * (nb_return + 1))))
		return (0);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &((*map)[i])) > 0)
		i++;
	close(fd);
	(*map)[i] = NULL;
	return (1);
}
