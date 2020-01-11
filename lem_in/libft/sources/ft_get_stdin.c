/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:08:18 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/21 22:00:31 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_stdin(char ***map)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_str_is_void(line))
			break ;
		ft_strtabadd(map, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
