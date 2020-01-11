/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 22:53:55 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/11 21:19:50 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char const *s)
{
	int		i;

	if (s && !(i = 0))
	{
		while (s[i])
			i++;
		if (write(1, s, i) == -1)
			return ;
	}
}
