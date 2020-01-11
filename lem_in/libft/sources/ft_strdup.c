/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:20:26 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/01 22:37:24 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(src) + 1));
	if (str)
		return (ft_strcpy(str, src));
	else
		return (NULL);
}
