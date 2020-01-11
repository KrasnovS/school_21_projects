/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_from_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:43:11 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/21 19:31:52 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_f_t(const char *src, size_t from, size_t to)
{
	char *str;

	if (from > to)
		return (NULL);
	if (to > (ft_strlen(src) - 1))
		to = ft_strlen(src) - 1;
	str = (char *)malloc(sizeof(char) * (to - from + 2));
	if (str)
		return (ft_strcpy_f_t(str, src, from, to));
	else
		return (NULL);
}
