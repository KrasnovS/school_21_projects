/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_intmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:17:46 by lfarlen           #+#    #+#             */
/*   Updated: 2019/12/13 19:43:34 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoi(char const *str)
{
	int					i;
	int					neg;
	unsigned long long	result;

	i = 0;
	neg = 1;
	result = 0;
	while (*str == ' ' || (*str > '\a' && *str <= '\r'))
		str++;
	if ((*str == '-' && (neg = -1)) || *str == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * neg);
}

char		ft_check_intmax(char *str)
{
	int len;

	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	if (!len || len > 10 || (len == 10 && *str == '2'
					&& ft_atoi(str + 1) > 147483647))
		return (0);
	return (1);
}
