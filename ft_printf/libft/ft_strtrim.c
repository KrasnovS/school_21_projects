/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:23:32 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/19 22:05:46 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	q;
	unsigned int	w;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	w = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	q = ft_strlen(s) - 1;
	while (s[q] == ' ' || s[q] == '\n' || s[q] == '\t')
		q--;
	if (!(str = (char *)malloc(sizeof(char) * (q - i + 2))))
		return (NULL);
	while (w < q - i + 1)
	{
		str[w] = s[i + w];
		w++;
	}
	str[w] = '\0';
	return (str);
}
