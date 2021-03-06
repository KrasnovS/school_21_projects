/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_unsigned_itoa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:44:07 by prawney           #+#    #+#             */
/*   Updated: 2019/07/31 18:44:09 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_base_string(t_format *f, unsigned long long num, int order, \
	int dif)
{
	if (f->type == 5)
		while (--order > 0)
		{
			f->str[order + dif - 1] = (num % 8) + 48;
			num /= 8;
		}
	else
		while (--order > 0)
		{
			if ((num % 16) > 9)
			{
				if (f->type == 7 || f->type == 2)
					f->str[order + dif - 1] = (num % 16) + 87;
				else
					f->str[order + dif - 1] = (num % 16) + 55;
			}
			else
				f->str[order + dif - 1] = (num % 16) + 48;
			num /= 16;
		}
	if (f->len > 1 && (f->str[1] == 'x' || f->str[1] == 'X'))
		order++;
	while (++order < dif)
		f->str[order] = '0';
}

static void	add_prefix(char *str, t_format *f, int *dif)
{
	str[0] = '0';
	if (f->type == 7 || f->type == 2)
	{
		str[1] = 'x';
		*dif += 2;
	}
	else if (f->type == 8)
	{
		str[1] = 'X';
		*dif += 2;
	}
	else if (!(f->type == 5 && f->order < f->precision))
		*dif += 1;
}

static int	pft_oct_n_gex_order(unsigned long long num, t_format *f)
{
	if (num == 0)
	{
		if (f->precision == 0 && !(f->type == 5 && f->flags[1]))
			return (0);
		return (1);
	}
	f->order = 0;
	if (f->type == 5)
		while (num > 0)
		{
			num /= 8;
			f->order++;
		}
	else
		while (num > 0)
		{
			num /= 16;
			f->order++;
		}
	return (f->order);
}

static void	check_sign_n_prec_unsigned(unsigned long long n, int *dif, \
	t_format *f)
{
	*dif = 0;
	if (f->len < f->precision)
	{
		*dif = f->precision - f->len;
		f->len = f->precision;
		if (f->type == 5)
			return ;
	}
	if (f->flags[1] && (n != 0 || f->type == 2) && (f->type == 2 || \
		f->type == 5 || f->type == 7 || f->type == 8))
	{
		if (f->type == 5)
			f->len++;
		else
			f->len += 2;
		if (f->width > f->len && f->flags[2] && !f->flags[3]\
			&& f->precision < 0)
			f->len = f->width;
	}
}

char		*pft_unsigned_itoa(unsigned long long num, t_format *f)
{
	int					dif;

	if (f->type == 6)
		f->len = pft_order(num, f);
	else
		f->len = pft_oct_n_gex_order(num, f);
	check_sign_n_prec_unsigned(num, &dif, f);
	if (!(f->str = ft_strnew(f->len)))
		return (NULL);
	if (f->flags[1] && (num != 0 || f->type == 2) && f->type != 6)
		add_prefix(f->str, f, &dif);
	else
		f->str[0] = '0';
	if (f->type == 6)
		set_string(f->str, num, (f->len - dif), dif);
	else
		set_base_string(f, num, (f->len - dif + 1), dif);
	return (f->str);
}
