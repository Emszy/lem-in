/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags		check_wid(char *fmt, t_flags flags, va_list ap)
{
	flags.width = ft_atoi(fmt);
	while (ft_isdigit(*fmt))
		fmt++;
	if (*fmt == '*')
	{
		flags.width = va_arg(ap, int);
		fmt++;
	}
	if (flags.precision < 0)
		flags.precision = 0;
	return (flags);
}

t_flags		check_precis(char *fmt, t_flags flags, va_list ap)
{
	fmt++;
	flags.precision = ft_atoi(fmt);
	while (ft_isdigit(*fmt))
		fmt++;
	if (*fmt == '*')
	{
		flags.precision = va_arg(ap, int);
		fmt++;
	}
	return (flags);
}

t_flags		first_flags(char *fmt, t_flags flags)
{
	if (*fmt == '-')
	{
		flags.neg = 1;
		flags.zero_spacer = 0;
	}
	else if (*fmt == '+')
		flags.plus_sign = 1;
	else if (*fmt == ' ')
		flags.space = 1;
	else if (*fmt == '#')
		flags.hash = 1;
	else if (*fmt == '0')
	{
		if (flags.neg == 0)
			flags.zero_spacer = 1;
	}
	return (flags);
}

t_flags		check_flags(char *fmt, t_flags flags, va_list ap)
{
	int pass_flags;

	flags.width = 0;
	pass_flags = 0;
	while (*fmt && !ft_isalpha(*fmt) && *fmt != '%')
	{
		if (pass_flags == 0)
			flags = first_flags(fmt, flags);
		if ((ft_isdigit(*fmt) || *fmt == '*') &&
			flags.width == 0 && *fmt != '0')
		{
			flags = check_wid(fmt, flags, ap);
			pass_flags = 1;
		}
		if (*fmt == '.')
		{
			flags = check_precis(fmt, flags, ap);
			return (flags);
		}
		fmt++;
	}
	return (flags);
}

t_flags		check_mod(char *fmt, t_flags flags)
{
	if (*fmt == 'h' && *fmt + 1 && *fmt + 1 != 'h')
		flags.h = 1;
	else if (*fmt == 'h' && *fmt + 1 && *fmt + 1 == 'h')
		flags.hh = 1;
	else if (*fmt == 'l' && *fmt + 1 && *fmt + 1 != 'l')
		flags.l = 1;
	else if (*fmt == 'l' && *fmt + 1 && *fmt + 1 == 'l')
		flags.ll = 1;
	else if (*fmt == 'j')
		flags.j = 1;
	else if (*fmt == 'z')
		flags.z = 1;
	return (flags);
}
