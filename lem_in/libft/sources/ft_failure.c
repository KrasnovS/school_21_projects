/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_failure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:44:14 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/29 21:16:40 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_failure(char *str, void *ret_value)
{
	ft_putcolor(str, RED);
	ft_putchar('\n');
	return (ret_value);
}
