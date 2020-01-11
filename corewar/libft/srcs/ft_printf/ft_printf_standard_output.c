/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_standard_output.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarlen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:42:22 by prawney           #+#    #+#             */
/*   Updated: 2019/12/13 20:26:48 by lfarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_char_output(t_var *var, char **output)
{
	int		i;
	int		len;

	ft_get_attributes(var);
	var->prec = 0;
	len = 1;
	if (var->width == 0)
		var->width = len;
	if (!(*output = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (ft_putstr("error from malloc in ft_char_output.\n"));
	i = -1;
	while (++i < var->width)
		output[0][i] = ' ';
	if (var->leftjustify)
		output[0][0] = (char)var->ll;
	else
		output[0][var->width - 1] = (char)var->ll;
	var->varlen += var->width;
}

void	ft_string_output(t_var *var, char **output)
{
	int		i;
	int		len;

	ft_get_attributes(var);
	var->s = (var->name == '%') ? "%" : var->s;
	len = var->s ? (int)ft_strlen(var->s) : 0;
	if (!var->s)
		return (ft_return_null(var, output));
	if (var->prec == -1 || var->prec > len)
		var->prec = len;
	len = len > var->prec ? var->prec : len;
	var->width = var->width < len ? len : var->width;
	if (!(*output = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (ft_putstr("error from malloc in ft_string_output.\n"));
	i = -1;
	while (++i < var->width)
		output[0][i] = ' ';
	if ((i = -1) && var->s && var->leftjustify)
		while (++i < len)
			output[0][i] = var->s[i];
	if (var->s && !var->leftjustify)
		while (++i < len)
			output[0][i + var->width - len] = var->s[i];
	output[0][var->width] = '\0';
	var->varlen += var->width;
}

void	ft_unsigned_output(t_var *var, char **output)
{
	int		len;

	ft_get_attributes(var);
	ft_get_format(var);
	ft_apply_format(var);
	var->s = ft_ultoa(0, 10, var, var->ull);
	if (var->ksep)
		ft_apply_ksep(var);
	if (var->prec == 0 && var->ull == 0)
		var->s[0] = '\0';
	len = (int)ft_strlen(var->s);
	len > var->prec ? (var->prec = len) : 0;
	if (var->width < var->prec)
		var->width = var->prec;
	if (!(*output = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (ft_putstr("error from malloc in ft_unsigned_output.\n"));
	ft_apply_flags(output, len, var);
	var->varlen += var->width;
	free(var->s);
}

void	ft_converted_output(t_var *var, char **output)
{
	int		len;
	char	base;
	char	prefix;

	base = (var->name == 'o' ? 8 : 16);
	ft_get_attributes(var);
	ft_get_format(var);
	ft_apply_format(var);
	prefix = (var->name == 'p' || ((var->name == 'x' || var->name == 'X')
										&& var->ull != 0 && var->hash) ? 2 : 0);
	prefix = (var->name == 'o' && var->hash) ? 1 : prefix;
	var->prec = var->zeropadding ? var->width - prefix : var->prec;
	var->s = ft_ultoa(prefix, base, var, var->ull);
	if (var->prec == 0 && var->ull == 0 && var->name != 'p')
		var->s[0] = '\0';
	len = (int)ft_strlen((var->s));
	var->prec = var->name == 'o' && var->hash && var->ull == 0 ? 1 : len;
	if (var->width < var->prec)
		var->width = var->prec;
	if (!(*output = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (ft_putstr("error from malloc in ft_converted_output.\n"));
	ft_apply_flags(output, len, var);
	var->varlen += var->width;
	free(var->s);
}

void	ft_integer_output(t_var *var, char **output)
{
	int		len;

	ft_get_attributes(var);
	ft_get_format(var);
	ft_apply_format(var);
	var->s = ft_ltoa(var->ll);
	if (var->ksep)
		ft_apply_ksep(var);
	if (var->prec == 0 && var->ll == 0)
		var->s[0] = '\0';
	len = ft_strlen(var->s);
	len > var->prec ? (var->prec = len) : 0;
	if ((var->space || var->showsign || var->ll < 0))
		var->prec = var->prec + 1;
	if (var->width < var->prec)
		var->width = var->prec;
	if (!(*output = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (ft_putstr("error from malloc in ft_integer_output.\n"));
	ft_apply_flags(output, len, var);
	var->varlen += var->width;
	free(var->s);
}
