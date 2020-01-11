/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:19:46 by prawney           #+#    #+#             */
/*   Updated: 2018/12/19 20:49:50 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arrjoin(char **arr, int len)
{
	size_t	s_len;
	size_t	j;
	int		i;
	char	*str;

	if (len < 1)
		return (NULL);
	s_len = 0;
	i = -1;
	while (++i < len)
		s_len += ft_strlen(arr[i]);
	if (!(str = ft_strnew(s_len + (len - 1))))
		return (NULL);
	i = -1;
	s_len = -1;
	while (++i < len)
	{
		j = -1;
		while (arr[i][++j] != '\0')
			str[++s_len] = arr[i][j];
		if (i != (len - 1))
			str[++s_len] = ' ';
	}
	return (str);
}
