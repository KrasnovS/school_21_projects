/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:22:12 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/13 19:48:07 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char const *s)
{
	int		len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void		ft_join3(char **s1, char const *s2, char const *s3)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = ft_strlen(*s1);
	j = ft_strlen(s2);
	k = ft_strlen(s3);
	if (!(new = (char *)malloc(sizeof(char) * (i + j + k + 1))))
		return ;
	new[i + j + k] = '\0';
	while (--k >= 0)
		new[i + j + k] = s3[k];
	while (--j >= 0)
		new[i + j] = s2[j];
	while (--i >= 0)
		new[i] = (*s1)[i];
	free(*s1);
	*s1 = new;
}
