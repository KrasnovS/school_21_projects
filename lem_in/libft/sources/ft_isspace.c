/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 21:15:30 by lfarlen           #+#    #+#             */
/*   Updated: 2019/01/25 21:19:02 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(unsigned int c)
{
	if (c == '\n' || c == ' ' || c == '\f' || c == '\t' ||
			c == '\r' || c == '\v')
		return (1);
	else
		return (0);
}
