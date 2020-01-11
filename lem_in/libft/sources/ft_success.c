/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:19:27 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/29 21:40:27 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_success(char *str, int ret_value)
{
	ft_putcolor(str, GREEN);
	ft_putchar('\n');
	return (ret_value);
}
