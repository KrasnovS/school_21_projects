/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_attributes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:42:54 by prawney           #+#    #+#             */
/*   Updated: 2019/12/13 20:14:48 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	ft_justify_output(char *output, int len, t_var *var)
{
	int		i;

	if ((i = -1) && var->leftjustify)
	{
		while (++i < var->prec - len)
			output[i] = '0';
		--i;
		while (++i < var->prec)
			output[i] = var->s[i - var->prec + len];
		--i;
		while (++i < var->width)
			output[i] = ' ';
	}
	if (!var->leftjustify)
	{
		while (++i < var->width - var->prec)
			output[i] = ' ';
		--i;
		while (++i < var->width - len)
			output[i] = '0';
		--i;
		while (++i < var->width)
			output[i] = var->s[i - var->width + len];
	}
	output[var->width] = '\0';
}

void		ft_apply_flags(char **output, int len, t_var *var)
{
	if (var->hash && var->name == 'o' && var->ull == 0)
	{
		var->s[0] = '0';
		var->s[1] = '\0';
		len = (int)ft_strlen(var->s);
	}
	if (var->zeropadding && ((var->prelock && !ft_strchr("fge", var->name))
		|| var->leftjustify))
		var->zeropadding = 0;
	if (var->zeropadding)
		var->prec = var->width;
	ft_justify_output(*output, len, var);
	if (ft_strchr("difge", var->name) && var->neg == -1)
		output[0][var->leftjustify ? 0 : var->width - var->prec] = '-';
	if (var->showsign && ft_strchr("difge", var->name) && var->neg == 1
		&& !(var->space = 0))
		output[0][var->leftjustify ? 0 : var->width - var->prec] = '+';
	if (var->space && ft_strchr("difge", var->name) && var->neg == 1)
		output[0][var->leftjustify ? 0 : var->width - var->prec] = ' ';
}

void		ft_apply_format(t_var *v)
{
	if (v->name == 'd' || v->name == 'i')
	{
		v->ll = (v->lf == 0 && v->hflag == 0 ? (int)v->ll : v->ll);
		v->ll = (v->lf == 1 ? (long)v->ll : v->ll);
		v->ll = (v->hflag == 1 ? (short)v->ll : v->ll);
		v->ll = (v->hflag == 2 ? (char)v->ll : v->ll);
		v->neg = (v->ll < 0 ? -1 : 1);
	}
	if (v->name == 'o' || v->name == 'u' || v->name == 'x' || v->name == 'X')
	{
		v->ull = (v->lf == 0 && v->hflag == 0)
									? (unsigned)v->ull : v->ull;
		v->ull = (v->lf == 1) ? (unsigned long)v->ull : v->ull;
		v->ull = (v->hflag == 1) ? (unsigned short)v->ull : v->ull;
		v->ull = (v->hflag == 2) ? (unsigned char)v->ull : v->ull;
	}
}

int			ft_exp_sorting(t_var *var, long double dec, long double *nb)
{
	int			i;

	i = 0;
	if (dec < 1.0L)
	{
		while (dec < 1.0L && (dec = dec * 10.0L))
			i++;
		var->s = ft_dtoexp(var, dec / 10, i, nb);
		return (-i);
	}
	while (dec >= 1.0L && (dec = dec / 10.0L))
		i++;
	var->s = ft_dtoexp(var, dec, i, nb);
	return (i - 1);
}

char		*ft_date_init(unsigned long long nb)
{
	char	*d;
	char	*s1;
	int		len;

	d = ft_ltoa(nb);
	len = ft_strlen(d);
	while (len < 8)
	{
		s1 = d;
		d = ft_strjoin("0", d);
		free(s1);
		len++;
	}
	if ((d[0] == '0' && d[1] == '0') || (d[1] == '0' && d[2] == '0')
		|| (d[0] == '3' && d[1] > '1') || (d[2] == '1' && d[3] > '2')
		|| d[0] > '3' || d[2] > '1' || len > 8)
		return (NULL);
	return (d);
}
