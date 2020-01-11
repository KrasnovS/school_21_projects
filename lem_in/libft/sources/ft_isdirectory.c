/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdirectory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 21:12:26 by lfarlen           #+#    #+#             */
/*   Updated: 2019/01/25 21:16:18 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isdirectory(char *path)
{
	DIR *ret;

	if ((ret = opendir(path)) == NULL)
		return (0);
	else
	{
		closedir(ret);
		return (1);
	}
}
