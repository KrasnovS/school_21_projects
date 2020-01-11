/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:39:43 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/19 22:14:41 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *str)
{
	int nb_word;
	int i;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 1)
			i++;
		else
		{
			while ((ft_isspace(str[i]) == 0) && str[i] != '\0')
				i++;
			nb_word++;
		}
	}
	return (nb_word);
}
