/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onumbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_size(uintmax_t num, int base)
{
	int len;

	len = 1;
	while (num /= base)
		len++;
	return (len);
}

void		print_num(char *str, t_flags flags)
{
	int len;

	len = ft_strlen(str);
	if (flags.neg)
	{
		ft_putstr(str);
		prepend_width(flags, flags.width - len);
	}
	else
	{
		prepend_width(flags, flags.width - len);
		ft_putstr(str);
	}
}

void		o_to_s(uintmax_t num, t_flags flags)
{
	int		len;
	char	*n;

	len = get_size(num, 8);
	if (flags.precision > len)
		len = flags.precision;
	n = ft_strnew(len);
	n[len] = '\0';
	while (--len >= 0)
	{
		if (num != 0)
			n[len] = num % 8 + '0';
		else
			n[len] = '0';
		num /= 8;
	}
	if (flags.hash)
	{
		ft_putstr("0");
		flags.width -= 1;
	}
	print_num(n, flags);
}

uintmax_t	promoting_o(va_list ap, t_flags flags, char *fmt)
{
	uintmax_t	res;

	if (*fmt == 'o' && flags.hh)
		res = (unsigned char)va_arg(ap, int);
	else if (*fmt == 'o' && flags.h)
		res = (unsigned short)va_arg(ap, int);
	else if (*fmt == 'o' && flags.ll)
		res = va_arg(ap, unsigned long long);
	else if ((*fmt == 'o' && flags.l) || *fmt == 'O')
		res = va_arg(ap, unsigned long);
	else if (*fmt == 'o' && flags.j)
		res = va_arg(ap, uintmax_t);
	else if (*fmt == 'o' && flags.z)
		res = va_arg(ap, ssize_t);
	else
		res = va_arg(ap, unsigned int);
	return (res);
}

void		onum_parse(va_list ap, t_flags flags, char *fmt)
{
	uintmax_t	res;

	res = promoting_o(ap, flags, fmt);
	if (flags.hash && res == 0)
	{
		prepend_width(flags, flags.width);
		ft_putchar('0');
		return ;
	}
	if (flags.width == 0 && flags.precision && res == 0)
		return ;
	if (flags.precision && res == 0)
	{
		prepend_width(flags, flags.width);
		ft_putchar(' ');
		return ;
	}
	o_to_s(res, flags);
}
