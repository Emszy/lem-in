/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xnumbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		x_mod(t_flags flags, char *fmt, char *new)
{
	int size;

	size = 0;
	if (flags.hash && !flags.zero_spacer)
	{
		new[1] = 'x';
		new[0] = '0';
	}
	if (*fmt == 'X')
	{
		while (new[size])
		{
			new[size] = ft_toupper(new[size]);
			size++;
		}
	}
	if (flags.hash && flags.zero_spacer)
	{
		if (*fmt == 'x')
			ft_putstr("0x");
		else if (*fmt == 'X')
			ft_putstr("0X");
		flags.width -= 2;
	}
	print_num(new, flags);
}

void		x_to_s(uintmax_t n, t_flags flags, char *fmt, int size)
{
	char	*new;

	size = get_size(n, 16);
	if (n == 0)
		flags.hash = 0;
	if (flags.precision > size)
		size = flags.precision;
	if (flags.hash && !flags.zero_spacer)
		size += 2;
	new = ft_strnew(size);
	new[size] = '\0';
	while (--size >= 0)
	{
		if (n != 0)
		{
			if ((n % 16) > 9)
				new[size] = (n % 16) - 10 + 'a';
			else
				new[size] = (n % 16) + '0';
		}
		else
			new[size] = '0';
		n /= 16;
	}
	x_mod(flags, fmt, new);
}

uintmax_t	promoting_x(va_list ap, t_flags flags)
{
	uintmax_t	res;

	if (flags.hh)
		res = (unsigned char)va_arg(ap, int);
	else if (flags.h)
		res = (unsigned short)va_arg(ap, int);
	else if (flags.l)
		res = va_arg(ap, unsigned long);
	else if (flags.ll)
		res = va_arg(ap, unsigned long long);
	else if (flags.j)
		res = va_arg(ap, uintmax_t);
	else if (flags.z)
		res = va_arg(ap, ssize_t);
	else
		res = va_arg(ap, unsigned int);
	return (res);
}

void		xnum_parse(va_list ap, t_flags flags, char *fmt)
{
	uintmax_t	res;

	res = promoting_x(ap, flags);
	if (res == 0 && !flags.width && flags.precision)
		return ;
	if (res == 0 && flags.precision)
	{
		prepend_width(flags, flags.width);
		ft_putchar(' ');
		return ;
	}
	x_to_s(res, flags, fmt, 0);
}
