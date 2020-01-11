/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:43:46 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/11 21:14:49 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
