/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags		init_flags(t_flags flags)
{
	flags.hash = 0;
	flags.neg = 0;
	flags.plus_sign = 0;
	flags.space = 0;
	flags.zero_spacer = 0;
	flags.modula = 0;
	flags.precision = 0;
	flags.h = 0;
	flags.hh = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.j = 0;
	flags.z = 0;
	return (flags);
}

void		check_spec(char *fmt, t_flags flags, va_list ap)
{
	if (*fmt == '%')
		ft_putchar('%');
	if (*fmt == 'c' || *fmt == 'C')
		chars(ap, flags, *fmt);
	if (*fmt == 's' || *fmt == 'S')
		str_parse(ap, flags, *fmt);
	if (*fmt == 'i' || *fmt == 'd' || *fmt == 'D')
		num_parse(ap, flags, fmt);
	if (*fmt == 'u' || *fmt == 'U')
		unum_parse(ap, flags, fmt);
	if (*fmt == 'x' || *fmt == 'X')
		xnum_parse(ap, flags, fmt);
	if (*fmt == 'o' || *fmt == 'O')
		onum_parse(ap, flags, fmt);
	if (*fmt == 'p')
		p_to_s(va_arg(ap, void *), flags);
}

int			setup(char *fmt, va_list ap)
{
	t_flags flags;

	while (*fmt)
	{
		if (*fmt == '%' && fmt++)
		{
			flags = init_flags(flags);
			if (*fmt == 0)
				return (1);
			flags = check_flags(fmt, flags, ap);
			while (*fmt && !ft_isalpha(*fmt) && *fmt != '%')
				fmt++;
			flags = check_mod(fmt, flags);
			while ((*fmt == 'l' || *fmt == 'h' || *fmt == 'z'
					|| *fmt == 'j') && *fmt)
				fmt++;
			check_spec(fmt, flags, ap);
		}
		else
			ft_putchar(*fmt);
		fmt++;
	}
	return (1);
}

int			ft_printf(char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	setup(fmt, ap);
	va_end(ap);
	return (0);
}
