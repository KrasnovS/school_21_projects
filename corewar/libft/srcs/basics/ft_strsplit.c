/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 22:49:18 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/11 21:23:47 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	word_len(unsigned int i, char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static unsigned int	words_count(char const *s, char c, char ***tab)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (!(*tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	(*tab)[count] = NULL;
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	count;
	unsigned int	mark;
	unsigned int	i;
	unsigned int	j;

	if (!s || !(count = words_count(s, c, &tab)))
		return (NULL);
	i = 0;
	mark = 0;
	while (s[i] && !(j = 0))
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(tab[mark] = (char *)malloc(word_len(i, s, c) + 1)))
			return (NULL);
		while (s[i] && s[i] != c)
			tab[mark][j++] = s[i++];
		tab[mark++][j] = '\0';
		j++;
	}
	return (tab);
}
