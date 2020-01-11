/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 21:42:27 by lfarlen           #+#    #+#             */
/*   Updated: 2019/01/27 16:41:00 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int nb)
{
	int		result;
	char	*str;

	str = ft_itoa(nb);
	result = ft_strlen(str);
	free(str);
	return (result);
}
