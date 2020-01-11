/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prawney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:41:24 by prawney           #+#    #+#             */
/*   Updated: 2019/07/31 18:42:21 by prawney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_format(va_list *ap, const char *format, t_printf *p)
{
	t_format	f;

	p->i++;
	if (format[p->i] == '%')
		return (addnchar(p, '%', 1));
	tformat_init(&f, p);
	if (P == ' ' || P == '#' || P == '0' || P == '-' || P == '+')
		set_flags(p, format, &f);
	if (P == '.' || (P >= '0' && P <= '9') || P == '*')
		set_wnp(p, format, &f, ap);
	if (P == 'h' || P == 'l' || P == 'L')
		set_length(p, format, &f);
	if (P == 'c' || P == 'C' || P == 's' || P == 'S' || P == 'p' || P == 'f' \
		|| P == 'F' || P == 'd' || P == 'D' || P == 'i' || P == 'o' || \
			P == 'O' || P == 'u' || P == 'U' || P == 'x' || P == 'X' \
				|| P == '%')
		set_type(P, &f);
	else
	{
		p->i--;
		return (1);
	}
	if (!(p->method_arr[f.type](p, &f, ap)))
		return (free_str(&f));
	return (1);
}

static int	error_return(va_list *ap, t_printf *p)
{
	free_buf(p);
	va_end(*ap);
	return (-1);
}

int			ft_fdprintf(int fd, const char *format, ...)
{
	va_list		ap;
	t_printf	p;

	tprintf_init(&p);
	va_start(ap, format);
	while (format[p.i] != '\0')
	{
		while (format[p.i] != '%' && format[p.i] != '\0')
			p.i++;
		if (p.i != p.start)
			if (!join_f(format, &p))
				return (free_buf(&p));
		if (format[p.i] != '\0')
			if (!get_format(&ap, format, &p))
				return (free_buf(&p));
		if (format[p.i] != '\0')
			p.i++;
		p.start = p.i;
	}
	if (write(fd, p.str, p.len) == -1)
		return (error_return(&ap, &p));
	free_buf(&p);
	va_end(ap);
	return (p.len);
}
