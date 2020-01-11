/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:51:53 by lfarlen           #+#    #+#             */
/*   Updated: 2018/12/03 21:21:49 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		count;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == to_find[0])
		{
			count = 0;
			while (str[count] != '\0' && to_find[count] != '\0')
			{
				if (str[count] != to_find[count])
					break ;
				count++;
			}
			if (to_find[count] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
