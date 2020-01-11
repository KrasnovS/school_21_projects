/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:35:56 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/11 21:23:03 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(ret, 0, size + 1);
	return (ret);
}
